import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class MyMouseListener implements MouseListener, MouseMotionListener {
	public void mouseClicked(MouseEvent e) { }
	public void mouseEntered(MouseEvent e) { }
	public void mouseExited(MouseEvent e) { }
	public void mousePressed(MouseEvent e) { }
	public void mouseReleased(MouseEvent e) { }
	public void mouseMoved(MouseEvent e) { }

	public void mouseDragged(MouseEvent e) {
		int x = e.getX(); int y = e.getY();
		
		Component.cp = (Component)e.getSource();
		cp.setLocation(x+cp.getX()-25, y+cp.getY() -25);
		System.out.printf("x=%d, y=%d\n", x, y);
	}
}

public class GUI_8 {
	GUI_8() {
		MyMouseListener mymlsnr = new MyMouseListener();
		
		JFrame frame = new JFrame();
		JPanel panel = new JPanel();

		panel.setBackground(Color.white);
		panel.setpreferredSize(new Dimension(400, 400));
		
		JButton btn_end = new JButton("End");
		btn_end.setBounds(165, 360, 70, 30);
		btn_end.addActionListener(new ActionListener() {
			public void actionPerfermed(ActionEvent e) {
				System.exit(0);
				}
			} );
			
		ImageIcon img = new ImageIcon("Img.jpg");
		if(img == null) {
			System.out.println("Image not found"); System.exit(1);
			}
		JLabel lbl_ball = new JLabel(img);
		lbl_ball.setBounds(150, 150, 70, 70);
		lbl_ball.addMouseListener(mymlsnr);
		lbl_ball.addMouseMotionListener(mymlsnr);
			
		panel.setLayout(null);
		panel.add(btn_end);
		panel.add(lbl_ball);
		
		frame.getContentPane().add(panel);
		frame.pack();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);	
	}
	public static void main(String[] args) {
		GUI_8 main_obj = new GUI_8();
		System.out.println("Console thread is going out !!!");
	}
	
}
