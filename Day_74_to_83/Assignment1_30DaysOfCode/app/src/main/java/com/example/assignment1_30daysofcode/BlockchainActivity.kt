package com.example.assignment1_30daysofcode

import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.widget.Button
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class BlockchainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_blockchain)
        val Rbtn = findViewById<Button>(R.id.roadmapBtn)

        Rbtn.setOnClickListener{
            val intent = Intent(Intent.ACTION_VIEW, Uri.parse("https://roadmap.sh/blockchain"))
            startActivity(intent)
        }
    }
}