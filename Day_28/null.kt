fun main(){
    val text = "Dashing"  // non nullable variable
    println("$text is a non nullable variable")

    // declaration of a nullable variable

    var text2 : String? = "War Lord"
    if(text2 != null) println(text2)

    //  ?.  safe call operator
    text2 = null;
    println(text2?.length)

    //   !!.  non-null assertion
    text2 = "War Lord"
    println(text!!.length)

    // Elvis operator  ?:
    // It is used to return the not null value
    // even the conditional expression is null
    val text3: String? = null
    println(text3 ?: "The variable text3 is null")
}