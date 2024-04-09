package com.example.view_model

import android.content.Intent
import android.net.Uri
import android.os.Build
import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.viewModels
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.wrapContentHeight
import androidx.compose.material3.Button
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import coil.compose.AsyncImage
import com.example.view_model.ui.theme.View_modelTheme

class MainActivity : ComponentActivity() {
    private val viewModel by viewModels<ColorViewModel>()
    private val imageVM by viewModels<ImageViewModel>()
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            View_modelTheme {
                Column(
                    modifier = Modifier
                        .fillMaxSize()
                        .background(color = viewModel.colorV),
                    horizontalAlignment = Alignment.CenterHorizontally,
                    verticalArrangement = Arrangement.SpaceBetween
                ) {

//                    imageVM.uri?.let {
//                        AsyncImage(
//                            model = imageVM.uri,
//                            contentDescription = null
//                        )
//                    }
                    Spacer(modifier = Modifier.height(5.dp))
                    if (imageVM.uri != null) {
                        TextF("Image Received")
                        AsyncImage(model = imageVM.uri, contentDescription = null)
                    } else{
                        TextF("Image Not Received")
                        AsyncImage(model = R.drawable.img, contentDescription = null)
                    }

                    Column(
                        modifier = Modifier
                            .fillMaxWidth()
                            .wrapContentHeight()
                            .background(MaterialTheme.colorScheme.tertiary),
                        horizontalAlignment = Alignment.CenterHorizontally,
                        verticalArrangement = Arrangement.SpaceEvenly
                    ) {
                        val red:Color = Color(0xFFF05044)
                        Button(onClick = { viewModel.changeBackgroundColor(red, "Red") }) {
                            Text(text = "Red")
                        }

                        Text(
                            text = viewModel.textV,
                            fontSize = 20.sp
                        )

                        val blue:Color = Color(0xFF465FEB)
                        Button(onClick = { viewModel.changeBackgroundColor(blue, "Blue") }) {
                            Text(text = "Blue")
                        }


                        Button(onClick = {
                            val intent = Intent(applicationContext, SecondActivity::class.java)
                            startActivity(intent)
                        }) {
                            Text(text = "Next")
                        }

                    }
                }

            }
        }
    }

    override fun onNewIntent(intent: Intent?) {
        super.onNewIntent(intent)

        val uri = if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            intent?.getParcelableExtra(Intent.EXTRA_STREAM, Uri::class.java)
        } else {
            intent?.getParcelableExtra(Intent.EXTRA_STREAM)
        }

        imageVM.changeImage(uri)
    }
}

@Composable
fun TextF(text:String){
    Column(
        modifier = Modifier
            .fillMaxWidth()
            .background(MaterialTheme.colorScheme.primary),
        horizontalAlignment = Alignment.CenterHorizontally

    ) {
        Text(text = text, color = MaterialTheme.colorScheme.onBackground, fontSize = 14.sp)
    }
}

