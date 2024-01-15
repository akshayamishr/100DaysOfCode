package com.example.appoftheday


import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.core.content.ContextCompat
import com.bumptech.glide.Glide
import com.example.appoftheday.databinding.ActivityMainBinding


class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        val view = binding.root
        setContentView(view)

        // List of image URLs
        val imageUrls = listOf(
            "https://th.bing.com/th/id/R.90513fb8ab3c2978311261c2e2f92bb3?rik=BRkuRf%2bplEIN6A&riu=http%3a%2f%2fwallpaperheart.com%2fwp-content%2fuploads%2f2018%2f05%2fhd-pc-wallpapers-cool-mountain-valley.jpg&ehk=kTtJkrjfzog49uJO0%2fqcUpqxDH2idUi30dH31SBk4Vc%3d&risl=&pid=ImgRaw&r=0",
            "https://th.bing.com/th/id/R.e076842d59457d25d07294b73c3f30a0?rik=AGzedx0CsdkyXA&riu=http%3a%2f%2fwonderfulengineering.com%2fwp-content%2fuploads%2f2016%2f01%2fDesktop-Background-43.jpg&ehk=BFXGJRPE2FRZbII7F02CkND4uQN3Ek%2ff4S9eCaxPjO4%3d&risl=&pid=ImgRaw&r=0",
            "https://th.bing.com/th/id/R.05785b9425845d6388088855bc0b9eb5?rik=Ww661cd23KtrOg&riu=http%3a%2f%2fwallpaperheart.com%2fwp-content%2fuploads%2f2018%2f08%2fbest-wallpapers-for-pc-4.jpg&ehk=1Y5%2bWahOm4WUShhmz%2fA2sN2ttYDUwicd4E7VugVNLtw%3d&risl=&pid=ImgRaw&r=0",
            "https://www.nawpic.com/media/2020/desktop-backgrounds-nawpic-14.jpg",
        )

        // Variable to keep track of the current image index
        var currentImageIndex = 0

        // button listener  --> change the image
        binding.SetImageButton.setOnClickListener {

            binding.Title.text = "Image changed successfully"

//            val drawable = ContextCompat.getDrawable(this, R.drawable.image2)
//          binding.DownloadbleImage.setImageDrawable(drawable)

            Glide
                .with(this)
                //.load("")
                .load(imageUrls[currentImageIndex])
                .into(binding.DownloadbleImage);

            // Increment the index for the next image
            currentImageIndex++

            // Reset the index if it exceeds the number of images
            if (currentImageIndex >= imageUrls.size) {
                currentImageIndex = 0
            }
        }
    }
}