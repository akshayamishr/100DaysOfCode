package com.example.lazythings

import androidx.annotation.DrawableRes

data class Item(
    val title:String,
    @DrawableRes val image: Int
)
