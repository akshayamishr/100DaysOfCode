package com.example.basics

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.widget.Button
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity2 : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main2)
        val prevbtn = findViewById<Button>(R.id.prevBtn)
        val webbtn = findViewById<Button>(R.id.webBtn)
        val ytbtn = findViewById<Button>(R.id.ytBtn)

        prevbtn.setOnClickListener{
            val intent = Intent(applicationContext,MainActivity::class.java)
            startActivity(intent)
        }

        webbtn.setOnClickListener{
            val intent = Intent(Intent.ACTION_VIEW, Uri.parse("https://developer.android.com/guide/components/intents-filters"))
            startActivity(intent)
        }

        ytbtn.setOnClickListener{
            val intent = Intent(applicationContext,MainActivity3::class.java)
            startActivity(intent)
        }

    }
}