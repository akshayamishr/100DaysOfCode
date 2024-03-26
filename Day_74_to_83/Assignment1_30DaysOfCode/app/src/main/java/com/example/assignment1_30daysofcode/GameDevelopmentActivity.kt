package com.example.assignment1_30daysofcode

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.widget.Button
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class GameDevelopmentActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_game_development)
        val Rbtn = findViewById<Button>(R.id.GameRoadmap)

        Rbtn.setOnClickListener{
            val intent = Intent(Intent.ACTION_VIEW, Uri.parse("https://roadmap.sh/game-developer"))
            startActivity(intent)
        }

    }
}