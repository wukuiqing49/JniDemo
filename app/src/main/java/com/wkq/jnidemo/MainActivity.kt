package com.wkq.jnidemo

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.TextView
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        findViewById<TextView>(R.id.sample_text).text = JniUtil.stringFromJNI()
        findViewById<Button>(R.id.bt_change).setOnClickListener {
            var isInit = JniUtil.HancNetInit()
            Log.e("注册状态:", isInit.toString())
            Toast.makeText(this, "初始化状态" + isInit, Toast.LENGTH_LONG).show()
//            JniUtil.netConnect("1991",88,"cmd",20,1,1);
        }


    }

}