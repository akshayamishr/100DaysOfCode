package com.example.animation

sealed class Screen(val route:String) {

    object HomeScreen:Screen("HomeScreen")
    object SecondScreen:Screen("SecondScreen")
    object LastScreen:Screen("LastScreen")
}