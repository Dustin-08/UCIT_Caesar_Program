package com.example.caesar_android;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.widget.RadioButton;
import android.widget.RadioGroup;

public class MainActivity extends AppCompatActivity {

    RadioGroup radioGroup;
    RadioButton encryptoBtn, decryptoBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        encryptoBtn = findViewById(R.id.encryptoBtn);
        decryptoBtn = findViewById(R.id.decryptoBtn);
        radioGroup = findViewById(R.id.radioGroup);

        encrypto encryptoFragment = new encrypto();
        decryptro decryptoFragment = new decryptro();

        radioGroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                if (checkedId == R.id.encryptoBtn) {
                    changeFragment(encryptoFragment);
                } else {
                    changeFragment(decryptoFragment);
                }
            }
        });
    }
    private void changeFragment(Fragment fr){
        FragmentManager frmgr = getSupportFragmentManager(); // fragmentmanager 가지고 오기
        FragmentTransaction frtr = frmgr.beginTransaction(); // transaction 시작
        frtr.replace(R.id.frContainer, fr);
        frtr.commit(); // transaction 종료
    }
}