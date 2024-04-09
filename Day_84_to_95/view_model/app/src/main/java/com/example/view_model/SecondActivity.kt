package com.example.view_model

import android.content.ActivityNotFoundException
import android.content.Intent
import android.net.Uri
import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.Button
import androidx.compose.material3.Text
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.sp
import com.example.view_model.ui.theme.View_modelTheme


class SecondActivity: ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            View_modelTheme{
                Column(
                    modifier = Modifier.fillMaxSize(),
                    horizontalAlignment = Alignment.CenterHorizontally
                ) {
                    Text(text = "Second Activity", fontSize = 20.sp)

                    Button(onClick = {
                        val intent = Intent(Intent.ACTION_MAIN).also {
                            it.`package` = "com.google.android.youtube"
                        }
                        try {
                            startActivity(intent)
                        } catch (e:ActivityNotFoundException){
                            e.printStackTrace()
                        }
                    }, )
                    {
                        Text(text = "YouTube")
                    }

                    Button(onClick = {
                        val intent = Intent(Intent.ACTION_SEND).apply {
                            type = "text/plain"
                            putExtra(Intent.EXTRA_EMAIL, arrayOf("test@text.com"))
                            putExtra(Intent.EXTRA_SUBJECT,"This ais Subject")
                            putExtra(Intent.EXTRA_TEXT,"This is Text")

                        }
                        if(intent.resolveActivity(packageManager) != null){
                            startActivity(intent)
                        } else {
                            // Handle error if no activity found to handle the intent
                            Toast.makeText(applicationContext, "No activity found to handle the call", Toast.LENGTH_SHORT).show()
                        }
                    }, )
                    {
                        Text(text = "Mail Us")
                    }

                    Button(onClick = {
                        val latitude = -99.7749
                        val longitude = -122.4194

                        // Create a URI with the geo: scheme and location coordinates
                        val uri = Uri.parse("geo:$latitude,$longitude")

                        val intent = Intent(Intent.ACTION_VIEW).apply {
                            this.setPackage("com.google.android.apps.maps")
                            this.data = uri
                        }

                        try {
                            startActivity(intent)
                        }catch (e:ActivityNotFoundException){
                            println(e.message)
                        }

                    }, )
                    {
                        Text(text = "Location")
                    }

                    Button(onClick = {

                        val number = "9999999"

                        // Create a URI with the geo: scheme and location coordinates
                        val uri = Uri.parse("tel:$number")

                        val intent = Intent(Intent.ACTION_DIAL).apply {
                            this.data = uri
                        }

                        try {
                            startActivity(intent)
                        }catch (e:ActivityNotFoundException){
                            println(e.message)
                        }

                    }, )
                    {
                        Text(text = "Phone")
                    }
                }
            }
        }
    }
}

