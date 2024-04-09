package com.example.animation

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.material3.Text
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController

class SecondActivity : ComponentActivity(){
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContent{

            val navController = rememberNavController()

            NavHost(
                navController = navController,
                startDestination = Screen.HomeScreen.route
            ){

                composable(route = Screen.HomeScreen.route){
                    HomeScreen(navController = navController)
                }

                composable(route = Screen.SecondScreen.route){
                    SecondScreen(navController = navController)
                }

                composable(route = Screen.LastScreen.route){
                    LastScreen(navController = navController)
                }
            }
        }
    }
}

