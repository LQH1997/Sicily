import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Calculator extends JFrame {
    String[] texts = {"10", "", "5", "=", "", "+", "-", "*", "/", "OK"};
    JButton a = new JButton(texts[0]);
    JButton b = new JButton(texts[1]);
    JButton c = new JButton(texts[2]);
    JButton d = new JButton(texts[3]);
    JButton e = new JButton(texts[4]);
    JButton f = new JButton(texts[5]);
    JButton g = new JButton(texts[6]);
    JButton h = new JButton(texts[7]);
    JButton i = new JButton(texts[8]);
    JButton j = new JButton(texts[9]);
    JButton[] Buttons = {a,b,c,d,e,f,g,h,i,j};

    Calculator(String a) {
        setTitle(a);
        setVisible(true);
        setLayout(new FlowLayout());
        setBounds(100,100,550,250);
        int i = 0;
        for(i = 0; i < 10; i++) {
            Buttons[i].setPreferredSize(new Dimension(100, 100));
            if(i < 5) {Buttons[i].setEnabled(false);}
            if(i != 4) {Buttons[i].setFont(new Font("Arial",Font.PLAIN, 30));}
            else {Buttons[i].setFont(new Font("Arial",Font.PLAIN, 20));}
            add(Buttons[i]);
        }

        Buttons[5].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                Buttons[1].setText(texts[5]);
            }
        });

        Buttons[6].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                Buttons[1].setText(texts[6]);
            }
        });

        Buttons[7].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                Buttons[1].setText(texts[7]);
            }
        });

        Buttons[8].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                Buttons[1].setText(texts[8]);
            }
        });

        Buttons[9].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent a) {
                double b;
                String c = Buttons[1].getText();
                switch (c) {
                    case "+": b = 10 + 5;
                              break;
                    case "-": b = 10 - 5; 
                              break;
                    case "*": b = 10 * 5; 
                              break;
                    case "/": b = 10 / 5; 
                              break;
                    default: b = 0; 
                              break;
                }
                if(Buttons[1].getText() != "+" && Buttons[1].getText() != "-" && 
                   Buttons[1].getText() != "*" && Buttons[1].getText() != "/")
                     Buttons[4].setText("");
                else {Buttons[4].setText(Double.toString(b));}
            }
        });
    }
}

public class MyCalculator {
    public static void main(String args[]) {
        new Calculator("Easy Calculator");
    }
}
