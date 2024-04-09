package com.example.view_model

import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.setValue
import androidx.compose.ui.graphics.Color
import androidx.lifecycle.ViewModel

class ColorViewModel : ViewModel() {
    var colorV by mutableStateOf(Color.White)
        private set

    var textV by mutableStateOf("White")
        private set

    fun changeBackgroundColor(color: Color, text:String){
        colorV = color
        textV = text
    }
}