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

public class decryptro extends Fragment {
    RadioGroup radioGroup;
    RadioButton forwardBtn, backwardBtn;
    Button decryptoStartBtn;
    EditText chiperEdit, countEdit;
    TextView decryptoText;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_decryptro, container, false);

        forwardBtn = view.findViewById(R.id.forwardBtn);
        backwardBtn = view.findViewById(R.id.backwardBtn);
        radioGroup = view.findViewById(R.id.radioGroup);
        decryptoStartBtn = view.findViewById(R.id.decryptoStartBtn);
        chiperEdit = view.findViewById(R.id.chiperEdit);
        countEdit = view.findViewById(R.id.countEdit);
        decryptoText = view.findViewById(R.id.decryptoText);

        // "복호화 시작" 버튼 클릭 시 이벤트 처리
        decryptoStartBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 입력된 암호문과 칸 수를 가져옴
                String chiperText = chiperEdit.getText().toString();
                int shiftCount = Integer.parseInt(countEdit.getText().toString());
                int selectedRadioButtonId = radioGroup.getCheckedRadioButtonId();

                // 시저 암호화를 수행합니다.
                String decryptedText = "";

                // 선택된 방향에 따라 이동할 칸 수를 조정합니다.
                if (selectedRadioButtonId == R.id.forwardBtn) {
                    // 앞으로 이동
                    decryptedText = caesarDecrypt(chiperText, shiftCount);
                } else {
                    // 뒤로 이동
                    decryptedText = caesarDecrypt(chiperText, -shiftCount);
                }

                // 복호화된 결과를 표시합니다.
                decryptoText.setText("복호화: " + decryptedText);
            }
        });

        return view;
    }
    // 시저 복호화 메서드
    private String caesarDecrypt(String chiperText, int shiftCount) {
        StringBuilder result = new StringBuilder();

        // 암호문의 각 문자를 하나씩 처리하여 복호화
        for (int i = 0; i < chiperText.length(); ++i) {
            char ch = chiperText.charAt(i);

            // 알파벳인 경우에만 복호화 작업 수행
            if (Character.isLetter(ch)) {
                if (Character.isUpperCase(ch)) {
                    ch = (char) ('Z' - ('Z' - ch + shiftCount) % 26);
                } else {
                    ch = (char) ('z' - ('z' - ch + shiftCount) % 26);
                }
            }

            result.append(ch);
        }

        return result.toString();
    }
}