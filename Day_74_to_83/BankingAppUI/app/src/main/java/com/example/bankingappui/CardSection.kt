package com.example.bankingappui

import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.lazy.LazyRow
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.graphics.Brush
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.bankingappui.data.CardItem
import com.example.bankingappui.ui.theme.BlueEnd
import com.example.bankingappui.ui.theme.BlueStart
import com.example.bankingappui.ui.theme.GreenEnd
import com.example.bankingappui.ui.theme.GreenStart
import com.example.bankingappui.ui.theme.OrangeEnd
import com.example.bankingappui.ui.theme.OrangeStart
import com.example.bankingappui.ui.theme.PurpleEnd
import com.example.bankingappui.ui.theme.PurpleStart

fun getGradient(startColor:Color,endColor:Color):Brush{
    return Brush.radialGradient(colors = listOf(startColor,endColor))
}

val cardVisa1 = CardItem("Educational","Master Card",100.00, getGradient(OrangeStart,OrangeEnd),"7905 9336 9451 1677")
val cardVisa2 = CardItem("Travel","VISA",500.89, getGradient(PurpleStart, PurpleEnd),"3549 1495 7826 4816")
val cardMaster1 = CardItem("Savings","VISA",200.07, getGradient(GreenStart, GreenEnd),"2586 7411 1467 9535")
val cardMaster2 = CardItem("Official","Master Card",2862.00, getGradient(BlueStart, BlueEnd),"7056 5198 1307 1358")

val cards = listOf(cardVisa1, cardMaster1, cardVisa2, cardMaster2)



@Preview
@Composable
fun CardSection(){
    LazyRow {
        items(cards.size){index->
            RowItem(index)
        }
    }
}

@Composable
fun RowItem(index:Int){

    val card = cards[index]

    // logo of cards
    var image = painterResource(id = R.drawable.visa_logo)
    if(card.cardType == "Master Card")
        image = painterResource(id = R.drawable.mastercard_logo)

    // padding for the last element at its end
    var paddingAtEnd = 0.dp
    if(index == cards.size - 1) paddingAtEnd = 16.dp

    Box(
        modifier = Modifier
            .padding(start = 16.dp, end = paddingAtEnd)
    ) {
        Column(
            modifier = Modifier
                .clip(RoundedCornerShape(25.dp))
                .background(card.cardColor)
                .width(250.dp)
                .height(160.dp)
                .clickable {}
                .padding(vertical = 12.dp, horizontal = 16.dp),
            verticalArrangement = Arrangement.SpaceBetween
        ) {

            Image(
                painter = image,
                contentDescription = card.cardName,
                modifier = Modifier.width(60.dp)
            )

            Spacer(modifier = Modifier.height(10.dp))

            Row(
                modifier = Modifier.width(250.dp),
                horizontalArrangement = Arrangement.SpaceBetween,
                verticalAlignment = Alignment.CenterVertically
            ) {
                Text(
                    text = card.cardName,
                    color = Color.White,
                    fontSize = 17.sp,
                    fontWeight = FontWeight.Bold
                )

                Text(
                    text = "$ ${card.cardBalance}",
                    color = Color.White,
                    fontSize = 22.sp,
                    fontWeight = FontWeight.Bold
                )
            }

            Text(
                text = card.cardNumber,
                color = Color.White,
                fontSize = 18.sp,
                fontWeight = FontWeight.Bold,
            )

        }
    }
}