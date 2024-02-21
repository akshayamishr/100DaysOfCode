package com.example.musicapp

import com.example.musicapp.Data

data class MyData(
    val `data`: List<Data>,
    val next: String,
    val total: Int
)