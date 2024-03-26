package com.example.assignment1_30daysofcode

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.widget.Button
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class IosDev : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_ios_dev)
        val Rbtn = findViewById<Button>(R.id.IosRoadmap)

        Rbtn.setOnClickListener{
            val intent = Intent(Intent.ACTION_VIEW, Uri.parse("https://medium.com/@meetmendapara09/the-ios-developer-roadmap-in-2024-navigating-the-apple-ecosystem-34c3b88f1825"))
            startActivity(intent)
        }

    }
}