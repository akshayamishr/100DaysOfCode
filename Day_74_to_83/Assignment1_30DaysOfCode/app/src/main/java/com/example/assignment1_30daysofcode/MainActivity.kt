package com.example.assignment1_30daysofcode

import android.content.Intent
import android.os.Bundle
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.cardview.widget.CardView
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContentView(R.layout.activity_main)
        val androD = findViewById<CardView>(R.id.AndroidDev)
        val wedD = findViewById<CardView>(R.id.WedDev)
        val iosD = findViewById<CardView>(R.id.IOSDev)
        val ml = findViewById<CardView>(R.id.ML)
        val blockchain = findViewById<CardView>(R.id.BlockChain)
        val gameD = findViewById<CardView>(R.id.GameDev)

        androD.setOnClickListener{
            val intent = Intent(applicationContext,AndroidActivity::class.java)
            startActivity(intent)
        }

        wedD.setOnClickListener{
            val intent = Intent(applicationContext,WedDevActivity::class.java)
            startActivity(intent)
        }

        iosD.setOnClickListener{
            val intent = Intent(applicationContext,IosDev::class.java)
            startActivity(intent)
        }

        ml.setOnClickListener{
            val intent = Intent(applicationContext,MachineLearningActivity::class.java)
            startActivity(intent)
        }

        blockchain.setOnClickListener{
            val intent = Intent(applicationContext,BlockchainActivity::class.java)
            startActivity(intent)
        }

        gameD.setOnClickListener{
            val intent = Intent(applicationContext,GameDevelopmentActivity::class.java)
            startActivity(intent)
        }
    }
}