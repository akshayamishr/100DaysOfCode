package com.example.chatbot

import com.google.ai.client.generativeai.GenerativeModel
import com.google.ai.client.generativeai.type.BlockThreshold
import com.google.ai.client.generativeai.type.HarmCategory
import com.google.ai.client.generativeai.type.SafetySetting
import com.google.ai.client.generativeai.type.content
import com.google.ai.client.generativeai.type.generationConfig

object Model {
    val apiKey = ""
    val config = generationConfig {
        temperature = 0.9f
        topK = 16
        topP = 0.1f
        maxOutputTokens = 200
        stopSequences = listOf("red")
    }
    val safety  = listOf(
        SafetySetting(HarmCategory.HARASSMENT, BlockThreshold.MEDIUM_AND_ABOVE),
        SafetySetting(HarmCategory.HATE_SPEECH, BlockThreshold.MEDIUM_AND_ABOVE),
        SafetySetting(HarmCategory.SEXUALLY_EXPLICIT, BlockThreshold.MEDIUM_AND_ABOVE),
        SafetySetting(HarmCategory.DANGEROUS_CONTENT, BlockThreshold.MEDIUM_AND_ABOVE),
    )

    val generativeModel = GenerativeModel(
        modelName = "gemini-1.0-pro",
        apiKey = apiKey,
        generationConfig = config,
        safetySettings = safety
    )

}