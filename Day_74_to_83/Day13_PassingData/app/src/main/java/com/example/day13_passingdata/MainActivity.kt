package com.example.day13_passingdata

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    companion object{
        const val key = "MainActivity.key"
    }

    override fun onCreate(savedInstanceState: Bundle?) {


        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val order1 = findViewById<EditText>(R.id.eT1)
        val order2 = findViewById<EditText>(R.id.eT2)
        val order3 = findViewById<EditText>(R.id.eT3)
        val order4 = findViewById<EditText>(R.id.eT4)


        val btn = findViewById<Button>(R.id.orderBtn)

        btn.setOnClickListener {

            val orderList : String = order1.text.toString() + "^" + order2.text.toString() + "^" + order3.text.toString() + "^" + order4.text.toString()

            if(orderList.length > 3){
                val intent = Intent(applicationContext,OrderActivity::class.java)
                intent.putExtra(key,orderList)
                startActivity(intent)
            }
            else{
                Toast.makeText(this, "Please Enter a Order", Toast.LENGTH_SHORT).show()
            }
        }

    }
}