package com.example.chatapp.data

import com.google.ai.client.generativeai.GenerativeModel
import com.google.ai.client.generativeai.type.BlockThreshold
import com.google.ai.client.generativeai.type.HarmCategory
import com.google.ai.client.generativeai.type.ResponseStoppedException
import com.google.ai.client.generativeai.type.SafetySetting
import com.google.ai.client.generativeai.type.generationConfig
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext

object Model {
    val apiKey = "API KEY"
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



    suspend fun getResponse(prompt : String) : Chat{
        val generativeModel = GenerativeModel(
            modelName = "gemini-1.0-pro",
            apiKey = apiKey,
            generationConfig = config,
            safetySettings = safety
        )

        try {
            val response = withContext(Dispatchers.IO){
                generativeModel.generateContent(prompt)
            }
            return Chat(
                prompt = response.text?:"error",
                isFromUser = false
            )
        } catch (e:ResponseStoppedException){
            return Chat(
                prompt = e.message?:"error",
                isFromUser = false
            )
        }
    }
}