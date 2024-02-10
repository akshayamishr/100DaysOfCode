package com.example.myapplication

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class MyAdapter(
    private val data: List<Language>
) : RecyclerView.Adapter<MyAdapter.ItemViewHolder>() {

    //Setup variables to hold the instance of the views defined in your recyclerView item layout
    //Kinda like the onCreate method in an Activity
    inner class ItemViewHolder(view: View): RecyclerView.ViewHolder(view) {
        val name: TextView = view.findViewById(R.id.LangName)
        val structure: ImageView = view.findViewById(R.id.LangLogo)
    }

    //This is where you inflate the layout (Give each entry/row its look)
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ItemViewHolder {
        val inflatedView: View = LayoutInflater.from(parent.context)
            .inflate(R.layout.elements, parent, false)
        return ItemViewHolder(inflatedView)
    }

    // Set values to the views we pulled out of the recycler_view_row
    // layout file based on the position of the recyclerView
    override fun onBindViewHolder(holder: ItemViewHolder, position: Int) {
        val lang: Language = data[position]

        holder.name.text = lang.name
        holder.structure.setImageResource(lang.structure)
    }

    //The recyclerView just wants to know how many items are currently in your dataset
    override fun getItemCount(): Int {
        return data.size
    }
}