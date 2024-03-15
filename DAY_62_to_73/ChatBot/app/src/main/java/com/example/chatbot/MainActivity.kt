package com.example.chatbot

import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.chatbot.databinding.ActivityMainBinding
import com.google.android.material.textfield.TextInputEditText
import kotlinx.coroutines.runBlocking

class MainActivity : AppCompatActivity() {

    lateinit var prompt : TextInputEditText

    lateinit var binding: ActivityMainBinding



    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        prompt = binding.Prompt

        binding.sendbtn.setOnClickListener {
            if(prompt.text.toString().length > 0){
                    runBlocking{
                        getReply(prompt.text.toString()) }
                }else{
                    Toast.makeText(this,"Enter any Prompt",Toast.LENGTH_SHORT).show()
                }
        }
    }

    suspend fun getReply(query: String) {
        prompt.setText("")
        val response = Model.generativeModel.generateContent(query)
        binding.textView2.text = response.text.toString()
    }
}