import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class GUI_7 {
	GUI_7() throws InterruptedException {
		final int Up = 0, Dn = 1, Rt = 2, Lt = 3;
		int cx = 200-50, cy = 200 - 50, px = cx, py = cy;
		
		JFrame frame = new JFrame("GUI_10_7");
		JPanel panel = new JPanel();
		
		panel.setBackground(Color.white);
		panel.setPreferredSize(new Dimension(400, 400));

		JButton btn_end = new JButton("End");
		btn_end.setBounds(165, 360, 70, 30);
		btn_end.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
				}
				} );
		ImageIcon img = new ImageIcon("Ball.jpg");
		JLabel lbl_ball = new JLabel(img);
		lbl_ball.setBounds(cx, cy, 50, 50);

		panel.setLayout(null);
		panel.add(btn_end);
		panel.add(lbl_ball);
		
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		while(true) {
			int ewsn, disp;
			ewsn = (int)(Math.random() * 1000) %  4;
			disp = (int)(Math.random() * 1000) % 30;
			
			switch(ewsn) {
			case Up: cy -= disp; if (cy < 0) cy = 0; break;
			case Dn: cy += disp; if (360 -50 < cy) cy = 360-50; break;
			
			case Lt: cx -= disp; if (cx < 0) cx = 0; break;
			case Rt: cx += disp; if (400-50 < cx) cx = 400-50; break;
			}
			lbl_ball.setLocation(cx, cy);
			Thread.sleep(100);			
		}	
	}
		public static void main(String[] args) throws InterruptedException {
			GUI_7 main_obj = new GUI_7();
			System.out.println("Console thread is going out !!!");
		}
}
