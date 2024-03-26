package com.example.bankingappui.data

import androidx.compose.ui.graphics.Brush

data class CardItem(
    val cardName:String,
    val cardType:String,
    val cardBalance:Double,
    val cardColor:Brush,
    val cardNumber:String
)
