package com.wkq.jnidemo

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        findViewById<TextView>(R.id.sample_text).text = JniUtil.stringFromJNI()
        findViewById<Button>(R.id.bt_change).setOnClickListener {

            JniUtil.netConnect("1991",88,"cmd",20,1,1);
        }

        var isInit=JniUtil.HancNetInit()
        Log.e("注册状态:",isInit.toString())
    }

}