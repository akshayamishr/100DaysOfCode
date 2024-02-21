package com.example.musicapp

import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Headers
import retrofit2.http.Query

interface APIinterface {


    @Headers("X-RapidAPI-Key: 1d2fe3ddadmsh02aff19028ac049p12bd93jsne2ea1255174c","X-RapidAPI-Host: deezerdevs-deezer.p.rapidapi.com")

    @GET("search")
    fun getData(@Query("q") query: String) : Call<MyData>
}