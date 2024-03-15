package com.example.lazythings

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.unit.dp
import androidx.navigation.NavHostController
import androidx.navigation.compose.rememberNavController
import com.example.lazythings.ui.theme.LazyThingsTheme
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable


class MainActivity : ComponentActivity() {

    companion object{
        val items = listOf(
            Item(
                title = "item1",
                image = R.drawable.img1
            ),
            Item(
                title = "item2",
                image = R.drawable.img2
            ),
            Item(
                title = "item3",
                image = R.drawable.img3
            ),
            Item(
                title = "item4",
                image = R.drawable.img4
            ),
            Item(
                title = "item5",
                image = R.drawable.img5
            ),
            Item(
                title = "item6",
                image = R.drawable.img6
            ),
            Item(
                title = "item7",
                image = R.drawable.img7
            ),
            Item(
                title = "item8",
                image = R.drawable.img8
            ),
            Item(
                title = "item9",
                image = R.drawable.img9
            ),
            Item(
                title = "item10",
                image = R.drawable.img10
            ),
        )
    }


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            LazyThingsTheme {
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    val navHostController = rememberNavController()
                    NavHost(
                        navController = navHostController,
                        startDestination = "home_screen")
                    {
                        composable("home_screen"){
                            HomeScreen(navHostController = navHostController)
                        }

                        composable("lazy_row_screen"){
                            LazyRowScreen()
                        }

                        composable("lazy_column_screen"){
                            LazyColumnScreen()
                        }

                        composable("lazy_vertical_grid_screen"){
                            LazyVerticalGridScreen()
                        }

                        composable("lazy_horizontal_grid_screen"){
                            LazyHorizontalGridScreen()
                        }
                    }
                }
            }
        }
    }
}

@Composable
fun HomeScreen(navHostController:NavHostController)
{
    Column (
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.SpaceEvenly,

        modifier = Modifier
            .fillMaxSize()
            .background(MaterialTheme.colorScheme.primaryContainer)
            .clip(shape = RoundedCornerShape(17.dp)),

    ){
        Button(
            modifier = Modifier
                .clip(shape = RoundedCornerShape(17.dp))
                .background(MaterialTheme.colorScheme.secondary),
            onClick = { navHostController.navigate("lazy_row_screen") }) {
            Text(text = "Lazy Row ")
        }

        Button(
            modifier = Modifier
                .clip(shape = RoundedCornerShape(17.dp))
                .background(MaterialTheme.colorScheme.secondary),
            onClick = { navHostController.navigate("lazy_column_screen") }) {
            Text(text = "Lazy Column ")
        }

        Button(
            modifier = Modifier
                .clip(shape = RoundedCornerShape(17.dp))
                .background(MaterialTheme.colorScheme.secondary),
            onClick = { navHostController.navigate("lazy_vertical_grid_screen") }) {
            Text(text = "Lazy Vertical Grid ")
        }

        Button(
            modifier = Modifier
                .clip(shape = RoundedCornerShape(17.dp))
                .background(MaterialTheme.colorScheme.secondary),
            onClick = { navHostController.navigate("lazy_horizontal_grid_screen") }) {
            Text(text = "Lazy Horizontal Grid ")
        }
    }
}

