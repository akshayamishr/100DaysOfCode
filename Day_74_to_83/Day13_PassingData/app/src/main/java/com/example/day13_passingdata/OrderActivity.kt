package com.example.day13_passingdata

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.core.view.marginBottom
import kotlinx.coroutines.delay
import kotlinx.coroutines.runBlocking

class OrderActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContentView(R.layout.activity_order)

        val orders = intent.getStringExtra(MainActivity.key)

        val order1 = findViewById<TextView>(R.id.O1)
        val order2 = findViewById<TextView>(R.id.O2)
        val order3 = findViewById<TextView>(R.id.O3)
        val order4 = findViewById<TextView>(R.id.O4)

        var texts:MutableList<TextView> = mutableListOf(order1,order2,order3,order4)

        var i = 0
        var j = 0
        while(i < texts.size) {
            if(i < orders!!.length){
                val temp = getOrder(orders, j)
                j += temp.length + 1
                texts[i].text = temp
            }
            else{
                texts[i].height = 0
            }
            i++
        }
    }

    private fun getOrder(orders: String, j: Int): String {
        var order = ""
        var i = j
        while(i < orders.length){
            if(orders[i] == '^') break;
            order += orders[i++]
        }
        return order
    }
}