package com.example.calculator

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.TextView
import com.example.calculator.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {

        lateinit var binding: ActivityMainBinding
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)


        // click listeners for the buttons

        binding.btnPlus.setOnClickListener {
            Click(binding.btnPlus)
        }
        binding.btnMinus.setOnClickListener {
            Click(binding.btnMinus)
        }

        binding.btnMulti.setOnClickListener {
            Click(binding.btnMulti)
        }

        binding.btnDiv.setOnClickListener {
            Click(binding.btnDiv)
        }

        binding.btnMod.setOnClickListener {
            Click(binding.btnMod)
        }

        binding.btnC.setOnClickListener {
            Click(binding.btnC)
        }

        binding.btnAC.setOnClickListener {
            Click(binding.btnAC)
        }

        binding.btnAns.setOnClickListener {
            Click(binding.btnAns)
        }

        binding.btnDeci.setOnClickListener {
            Click(binding.btnDeci)
        }

        binding.btn0.setOnClickListener {
            Click(binding.btn0)
        }

        binding.btn1.setOnClickListener {
            Click(binding.btn1)
        }

        binding.btn2.setOnClickListener {
            Click(binding.btn2)
        }

        binding.btn3.setOnClickListener {
            Click(binding.btn3)
        }

        binding.btn4.setOnClickListener {
            Click(binding.btn4)
        }

        binding.btn5.setOnClickListener {
            Click(binding.btn5)
        }

        binding.btn6.setOnClickListener {
            Click(binding.btn6)
        }

        binding.btn7.setOnClickListener {
            Click(binding.btn7)
        }

        binding.btn8.setOnClickListener {
            Click(binding.btn8)
        }

        binding.btn9.setOnClickListener {
            Click(binding.btn9)
        }
    }

    private fun Click(v: View) {
        val id = v.id
        val input: TextView = findViewById(R.id.inputView)
        val output: TextView = findViewById(R.id.resultView)
        var strI = input.text.toString()
        val temp: Button = findViewById(id)

        when (v.id) {
            R.id.btnAC -> {
                clearDisplay(input, output)
            }
            R.id.btnC -> {
                clearResult(output)
            }
            R.id.btnAns -> {
                val result: Double = evaluate(strI, 0)
                displayResult(result, input, output)
            }
            R.id.btnPlus, R.id.btnMinus, R.id.btnMulti, R.id.btnDiv, R.id.btnMod -> {
                val op = checkOperator(strI)
                if (op != -1) {
                    val result: Double = evaluate(strI, 0)
                    displayResult(result, input, output)
                    strI = result.toString()
                }
                updateInputText(strI, temp.text.toString(), input)

            }
            else -> {
                appendToInputText(strI, temp.text.toString(), input)
            }
        }
    }

    private fun updateInputText(strI: String, value: String, input: TextView) {
        input.text = strI + value
    }

    private fun appendToInputText(strI: String, value: String, input: TextView) {
        if (strI[0] == '0') {
            input.text = value
        } else {
            input.text = strI + value
        }
    }

    private fun clearDisplay(input: TextView, output: TextView) {
        input.text = "0"
        output.text = "0"
    }

    private fun clearResult(output: TextView) {
        output.text = "0"
    }

    private fun displayResult(result: Double, input: TextView, output: TextView) {
        input.text = result.toString()
        output.text = result.toString()
    }

    private fun evaluate(str: String, startingIdx: Int): Double {
        var num1 = 0.0
        var num2 = 0.0
        var temp = 0.0
        var operator: Char = 'o'
        var isDecimal = false
        var decimalPlace = 0.1

        for (i in startingIdx until str.length) {
            val char = str[i]
            when {
                char in '0'..'9' -> {
                    if (isDecimal) {
                        temp += Character.getNumericValue(char) * decimalPlace
                        decimalPlace *= 0.1
                    } else {
                        temp = temp * 10 + Character.getNumericValue(char)
                    }
                }
                char == '.' -> {
                    isDecimal = true
                    decimalPlace = 0.1
                }
                char in setOf('+', '-', '*', '/', '%') -> {
                    num1 = temp
                    temp = 0.0
                    operator = char
                    isDecimal = false
                }
            }
        }
        num2 = temp

        return calculateResult(num1, num2, operator)
    }


    private fun calculateResult(num1: Double, num2: Double, operator: Char): Double {
        return when (operator) {
            '+' -> num1 + num2
            '-' -> num1 - num2
            '*' -> num1 * num2
            '/' -> if (num2 != 0.0) num1 / num2 else Double.NaN
            else -> Double.NaN
        }
    }

    private fun checkOperator(str1: String): Int {
        val len = str1.length
        for (i in 0..<len) {
            val temp = str1[i]
            if (temp == '+' || temp == '-' || temp == '/' || temp == '*' || temp == '%') return i
        }
        return -1
    }
}