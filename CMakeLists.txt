cmake_minimum_required(VERSION 3.5)
project(airbnb)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(airbnb求职大礼包)
include_directories(OA汇总)
include_directories("OA汇总/OA2(page)")
include_directories(OA汇总/模拟外交)
include_directories("/Users/mac/bits/stdc++.h")

add_executable(airbnb
        "airbnb求职大礼包/Aairbnb OA高频题汇总.docx.pdf"
        "airbnb求职大礼包/Airbnb Behavior Question汇总.docx.pdf"
        airbnb求职大礼包/Airbnb企业文化.docx.pdf
        airbnb求职大礼包/Airbnb最新招聘信息大汇总.docx.pdf
        airbnb求职大礼包/Airbnb最新面经大汇总.docx.pdf
        airbnb求职大礼包/Airbnb算法真题汇总.docx.pdf
        airbnb求职大礼包/Airbnb系统设计面试真题汇总.docx.pdf
        airbnb求职大礼包/Airbnb面试准备指南.docx.pdf
        airbnb求职大礼包/Airbnb面试流程梳理.pdf
        "airbnb求职大礼包/Lintcode IT企业模拟面试密码.pdf"
        "OA汇总/OA2(page)/2.txt"
        OA汇总/模拟外交/040630ezmmd9dzp1c1ymcy.png
        OA汇总/模拟外交/040631j7djwp74mv18fd1e.png
        OA汇总/模拟外交/040631xra0z7zx7rfw3zfw.png
        OA汇总/19.txt
        OA汇总/6.jpg
        OA汇总/OA12.png
        0
        "1.Palindrome Pairs.cpp"
        "10. meeting room.cpp"
        "11. preference list.cpp"
        "12.buddy list.cpp"
        "13.flight ticket list.cpp"
        "14.URL Shortener.cpp"
        15.wizards.cpp
        16.PourWater.cpp
        "17.text justification.cpp"
        "18.string pyramids transition matrix.cpp"
        "19.sliding game-followup.cpp"
        "19.sliding game.cpp"
        "2.Round numbers.cpp"
        "20.find median from large file of integers.cpp"
        "21.Multiply Strings.cpp"
        "22.CSV PARSER.cpp"
        "22.csv parser.png"
        "23.boggle game.cpp"
        "24.nights request on Airbnb.com.cpp"
        "25.edit distance.cpp"
        "26.rectangles intersect.cpp"
        27.CollatzConjecture.cpp
        "28.Simulate Diplomacy.cpp"
        "29.Regular Expression.cpp"
        "3.2D itertaor + remove().cpp"
        30.String_Case_Combinations.cpp
        "31.Finding Ocean.cpp"
        "32.Traveling Salesman.cpp"
        "33.Bank System.cpp"
        "34.Ternary Expression Parser.cpp"
        "35.Profitable Schemes.cpp"
        "36.Hogwarts Meetup.cpp"
        4.ip2cidr.cpp
        "5.Display Page list.cpp"
        "6.menu order.cpp"
        "8. Alien Dictionary.cpp"
        "9.有向图 求最少的点可以遍历所有点.cpp"
        "Airbnb - LeetCode.pdf"
        airbnb面经coding题目总结.pdf
        "airbnb面试题汇总 _ August's Box.pdf")
