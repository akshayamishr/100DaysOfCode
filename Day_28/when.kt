fun main(){
      // assigning values from conditionals
    val text = if (x >= y) "This is a string" else 1
    println("$text")
    // when statement
    val q = 2
    val text2 = when(true){
        // if any condition is true then no other condition will be checked
        (q in -1..9) -> "$q is less than 10 and grater than -2"
        (q > 0) -> "$q is greater then 0"
        else -> "$q is greater then 10"
    }
    println(text2)
}
