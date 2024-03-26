package com.example.basics

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import androidx.constraintlayout.widget.ConstraintLayout

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val hotBnt = findViewById<Button>(R.id.hot)
        val coolBnt = findViewById<Button>(R.id.cool)
        val text = findViewById<TextView>(R.id.text)
        val carrier = findViewById<ConstraintLayout>(R.id.container)
        val nextBnt = findViewById<Button>(R.id.nextBtn)

        hotBnt.setOnClickListener{
            text.setText("The screen is hot")
            carrier.setBackgroundColor(getResources().getColor(R.color.red))
        }

        coolBnt.setOnClickListener{
            text.setText("The screen is cold")
            carrier.setBackgroundColor(getResources().getColor(R.color.purple_700))
        }

        nextBnt.setOnClickListener{
            val intent = Intent(applicationContext,MainActivity2::class.java)
            startActivity(intent)
        }
    }
}