package com.example.animation

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavController


@Composable
fun LastScreen(navController : NavController){
    Column(
        verticalArrangement = Arrangement.SpaceBetween,
        modifier = Modifier
            .fillMaxSize()
            .background(MaterialTheme.colorScheme.primaryContainer),

        horizontalAlignment = Alignment.CenterHorizontally

    ) {
        Spacer(modifier = Modifier.height(10.dp))

        Text(
            fontSize = 17.sp,
            color = (MaterialTheme.colorScheme.onBackground),
            text = "Last Screen"
        )

        Button(onClick = {
            navController.popBackStack()
            navController.popBackStack()
        }) {
            Text(text = "Home Screen")
        }


        Button(onClick = {
            navController.popBackStack()
        }) {
            Text(text = "Second Screen")
        }

        Spacer(modifier = Modifier.height(15.dp))
    }
}