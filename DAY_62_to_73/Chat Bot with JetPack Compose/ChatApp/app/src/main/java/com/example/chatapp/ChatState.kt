package com.example.chatapp

import android.graphics.Bitmap
import com.example.chatapp.data.Chat

data class ChatState (
    val chatList: MutableList<Chat> = mutableListOf(),
    val prompt: String = ""
)