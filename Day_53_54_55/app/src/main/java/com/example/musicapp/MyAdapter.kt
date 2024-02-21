package com.example.musicapp

import android.app.Activity
import android.media.MediaPlayer
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageButton
import android.widget.ImageView
import android.widget.TextView
import androidx.core.net.toUri
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide

class MyAdapter(val context : Activity, val dataList : List<Data>):RecyclerView.Adapter<MyAdapter.MyViewHolder>() {
    class MyViewHolder(itemView:View):RecyclerView.ViewHolder(itemView) {
        val image: ImageView
        val title: TextView
        val play: ImageButton
        val pause: ImageButton

        init{
            image = itemView.findViewById(R.id.imageView)
            title = itemView.findViewById(R.id.titleNmae)
            pause = itemView.findViewById(R.id.pausebnt)
            play = itemView.findViewById(R.id.playbtn)
        }
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyViewHolder {
        // creates the view if layout Manager fails to do so
        val itemView = LayoutInflater.from(context).inflate(R.layout.elements,parent,false)
        return MyViewHolder(itemView)
    }

    override fun getItemCount(): Int {
        // returns the size of dataList
        return dataList.size
    }

    override fun onBindViewHolder(holder: MyViewHolder, position: Int) {
        val currentData = dataList[position]

        val mediaPlayer = MediaPlayer.create(context,currentData.preview.toUri())

        holder.title.text = currentData.title

        Glide
            .with(context)
            .load(currentData.album.cover)
            .placeholder(R.drawable.ic_launcher_foreground)
            .into(holder.image)

        holder.play.setOnClickListener{
            mediaPlayer.start()
        }
        holder.pause.setOnClickListener {
            mediaPlayer.stop()
        }
    }
}