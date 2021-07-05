import javax.swing.*;
import java.awt. *;  
import java.awt.event. *; 

class AEvent implements  ActionListener {
    JFrame frame = new JFrame("AGGIUNTA DI EVENTI");
    Container c = frame.getContentPane();

    JButton btn;
    JTextField text,txt;

    AEvent(){
        // Creo il bottone.
        btn = new JButton("CLICCAMI");
        btn.setBounds (100 , 120 , 100 , 30);
        // Creo casella di testo n.1
        text = new  JTextField ();  
        text.setBounds (60 , 50 , 170 , 20);  
        // Creo casella di testo n.2
        txt = new  JTextField ();  
        txt.setBounds(60,75,170,20);  

        btn.addActionListener(this); // Afferma l'evento "click" al nostro bottone.

        // Aggiungo i componenti nel "Container".
        c.add(btn);
        c.add(text); c.add(txt); 
        c.setBackground(Color.GREEN);

        // Impostazioni per la finestra di interfaccia.
        frame.setSize(300 , 300);  
        frame.setLayout (null);  
        frame.setVisible (true); 
        frame.setResizable(false); 
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e){
        // Quando si clicca il bottone...
        text.setText("Esercizio 13-12-2019"); txt.setText("Riuscito");
    }
    public static void main(String argv[]){
            new AEvent();
    }
}  
