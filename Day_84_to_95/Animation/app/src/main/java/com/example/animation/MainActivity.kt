package com.example.animation

import android.content.Intent
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.animation.animateColorAsState
import androidx.compose.animation.core.animateDpAsState
import androidx.compose.animation.core.tween
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.animation.ui.theme.AnimationTheme

class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContent {
            AnimationTheme {
                // A surface container using the 'background' color from the theme
                Surface(

                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    Screen()
                }
            }
        }
    }
}

@Preview
@Composable
fun Screen(){
    val mContext = LocalContext.current


    val isVisible = remember {
        mutableStateOf(false)
    }

    val isColor = remember {
        mutableStateOf(false)
    }

    val isCircle = remember {
        mutableStateOf(true)
    }

    val size = animateDpAsState(
        targetValue = if(isVisible.value)300.dp else 30.dp,
        label = "size",
        animationSpec = tween(
            3000,200
        )
    )

    val colorAnime = animateColorAsState(
        targetValue = if(isColor.value) Color.LightGray
                            else  Color.DarkGray,
        label = "color",
        animationSpec = tween(2000,100)

    )

    val shapeAnime = animateDpAsState(
        targetValue = if(isCircle.value) 30.dp else 200.dp,
        label = "shape",
        animationSpec = tween(2000,100)

    )

    Column(
        horizontalAlignment = Alignment.CenterHorizontally,
        modifier = Modifier
            .background(MaterialTheme.colorScheme.primaryContainer)
            .fillMaxSize(),

    ){
        Spacer(modifier = Modifier.height(30.dp))

        Button(onClick = {
            isVisible.value = !isVisible.value
        }) {
            Text(text = "Click Me")
        }

        Spacer(modifier = Modifier.height(30.dp))

//        AnimatedVisibility(
//            visible = isVisible.value,
//            enter = fadeIn() + expandHorizontally(),
//            exit = fadeOut() + shrinkHorizontally()
//            )
//        {
            Box(contentAlignment = Alignment.Center,
                modifier = Modifier
                    .size(size.value)
                    .clip(RoundedCornerShape(shapeAnime.value))
                    .background(colorAnime.value),

            ) {
                Button(onClick = {
                    isColor.value = !isColor.value
                }) {
                    Text(text = "Click Me")
                }
        }

        Spacer(modifier = Modifier.height(30.dp))

        Button(onClick = {
            isCircle.value = !isCircle.value
        }) {
            Text(text = "Shape")
        }

        Button(
            onClick = {
                mContext.startActivity(Intent(mContext,SecondActivity::class.java))
            }) {
            Text(text = "Navigation")
        }
    }
}