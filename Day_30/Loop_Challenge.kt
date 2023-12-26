fun main()
{
    var count = 0
    for(i in 1..20)
    {
        if(i % 2 == 0) {
            print("$i ")
            count++
        }
    }
    println("\nThere are $count even numbers between 1 and 20")
}