package com.example.appoftheday2.viewModel

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel

class ImageSet : ViewModel() {
    private var imageUrls = MutableLiveData<List<String>>()

    init {
        // Call the updateList function with a new list
        updateList()
    }
    private fun updateList() {
        // Assign a new list of image URLs to the MutableLiveData
        imageUrls.value = listOf(
            "https://th.bing.com/th/id/R.90513fb8ab3c2978311261c2e2f92bb3?rik=BRkuRf%2bplEIN6A&riu=http%3a%2f%2fwallpaperheart.com%2fwp-content%2fuploads%2f2018%2f05%2fhd-pc-wallpapers-cool-mountain-valley.jpg&ehk=kTtJkrjfzog49uJO0%2fqcUpqxDH2idUi30dH31SBk4Vc%3d&risl=&pid=ImgRaw&r=0",
            "https://th.bing.com/th/id/R.e076842d59457d25d07294b73c3f30a0?rik=AGzedx0CsdkyXA&riu=http%3a%2f%2fwonderfulengineering.com%2fwp-content%2fuploads%2f2016%2f01%2fDesktop-Background-43.jpg&ehk=BFXGJRPE2FRZbII7F02CkND4uQN3Ek%2ff4S9eCaxPjO4%3d&risl=&pid=ImgRaw&r=0",
            "https://th.bing.com/th/id/R.05785b9425845d6388088855bc0b9eb5?rik=Ww661cd23KtrOg&riu=http%3a%2f%2fwallpaperheart.com%2fwp-content%2fuploads%2f2018%2f08%2fbest-wallpapers-for-pc-4.jpg&ehk=1Y5%2bWahOm4WUShhmz%2fA2sN2ttYDUwicd4E7VugVNLtw%3d&risl=&pid=ImgRaw&r=0",
            "https://www.nawpic.com/media/2020/desktop-backgrounds-nawpic-14.jpg",
        )
    }

    private fun getSize(): Int {
        val imageUrlList = imageUrls.value
        return imageUrlList?.size ?: 0
    }

    fun getImage(idx: Int): String? {
        val imageUrlList = imageUrls.value
        return imageUrlList?.getOrNull(idx % getSize())
    }

}
