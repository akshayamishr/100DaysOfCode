package com.example.recycler

import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.bumptech.glide.request.RequestOptions


class Adapter(private val context: Context, private var imgList:List<String>, private var names:List<String>):
    RecyclerView.Adapter<Adapter.ViewHolder>(){
    class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView){

        val LangName : TextView = itemView.findViewById(R.id.LangName)
        val LangImg : ImageView = itemView.findViewById(R.id.LangImage)

        init {
            itemView.setOnClickListener{v: View ->
                val position:Int = adapterPosition
                Toast.makeText(itemView.context,"You clicked on ${position + 1}",Toast.LENGTH_LONG).show()
            }
        }

    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val v = LayoutInflater.from(parent.context).inflate(R.layout.elements,parent,false)
        return ViewHolder(v)
    }

    override fun getItemCount(): Int {
        return imgList?.size ?: 0
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {

        holder.LangName.text = names[position]
        val url:String = (imgList[position])

        Glide
            .with(context)
            .load(imgList[position])
            .apply(RequestOptions.centerCropTransform())
            .into(holder.LangImg)

    }
}