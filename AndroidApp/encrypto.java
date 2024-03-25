package com.example.caesar_android;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

public class encrypto extends Fragment {
    RadioGroup radioGroup;
    RadioButton forwardBtn, backwardBtn;
    Button encryptoStartBtn;
    EditText plainEdit, countEdit;
    TextView chiperText;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_encrypto, container, false);

        forwardBtn = view.findViewById(R.id.forwardBtn);
        backwardBtn = view.findViewById(R.id.backwardBtn);
        radioGroup = view.findViewById(R.id.radioGroup);
        encryptoStartBtn = view.findViewById(R.id.encryptoStartBtn);
        plainEdit = view.findViewById(R.id.plainEdit);
        countEdit = view.findViewById(R.id.countEdit);
        chiperText = view.findViewById(R.id.chiperText);

        // "암호화 시작" 버튼에 클릭 리스너를 등록합니다.
        encryptoStartBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 입력된 평문, 이동할 칸 수, 선택된 라디오 버튼을 가져옵니다.
                String plainText = plainEdit.getText().toString();
                int shiftCount = Integer.parseInt(countEdit.getText().toString());
                int selectedRadioButtonId = radioGroup.getCheckedRadioButtonId();

                // 시저 암호화를 수행합니다.
                String encryptedText = "";

                // 선택된 방향에 따라 이동할 칸 수를 조정합니다.
                if (selectedRadioButtonId == R.id.backwardBtn) {
                    // 뒤로 이동
                    encryptedText = caesarEncrypt(plainText, shiftCount);
                } else {
                    // 앞으로 이동
                    encryptedText = caesarEncrypt(plainText, -shiftCount);
                }

                // 암호화된 결과를 표시합니다.
                chiperText.setText("암호화: " + encryptedText);
            }
        });

        return view;
    }
    // 시저 암호화를 수행하는 메서드
    private String caesarEncrypt(String plainText, int shiftCount) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < plainText.length(); ++i) {
            char ch = plainText.charAt(i);

            if (Character.isLetter(ch)) {
                // 알파벳인 경우에만 암호화 작업을 수행합니다.
                if (Character.isUpperCase(ch)) {
                    ch = (char) ('A' + (ch - 'A' + shiftCount) % 26);
                } else {
                    ch = (char) ('a' + (ch - 'a' + shiftCount) % 26);
                }
            }

            result.append(ch);
        }

        return result.toString();
    }
}