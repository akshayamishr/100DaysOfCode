package com.example.myapplication

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val recyclerView: RecyclerView = findViewById(R.id.myrecycler)
        recyclerView.adapter = MyAdapter(createData())
        recyclerView.layoutManager = LinearLayoutManager(this)
    }

    private fun createData(): List<Language> {
        //Get data from the repository
        val names = Data.LanguageName
        val structures = Data.structures

        val LanguageData = ArrayList<Language>()
        LanguageID.values().forEach { languageID ->
            //If the Id is in all lists, add language to the ArrayList
            if (containsId(languageID, names, structures)) {
                LanguageData.add(
                    Language(
                        name = names[languageID]!!,
                        structure = structures[languageID]!!
                    )
                )
            }
        }

        return LanguageData
    }

    /**
     * Takes in a language id and checks if it is contained within all mappings passed
     */
    private fun containsId(languageID: LanguageID, vararg maps: Map<LanguageID, Any>): Boolean {
        maps.forEach {
            if (languageID !in it.keys) { return false }
        }
        return true
    }
}
