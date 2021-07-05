import java.util.*;
import javax.mail.*;
import javax.mail.internet.*;

public class InvioEmail{
	public static void main(String argv[]) throws Exception{
		String destinatario = " "; // inserire il destinatario.
		String mittente = "killuag09@gmail.com"; 
		
		Properties props = new Properties();
		props.put("mail.smtp.auth","true");
		props.put("mail.smtp.starttls.enable","true");
		props.put("mail.smtp.host", "smtp.gmail.com");
		props.put("mail.smtp.port", 587);
		
		Session session = Session.getDefaultInstance(props, new javax.mail.Authenticator()
		{
			protected PasswordAuthentication getPasswordAuthentication() {
				return new PasswordAuthentication(mittente," "); // inserire anche password.
			}
		});
		
		try {
			MimeMessage message = new MimeMessage(session);
			message.setFrom(new InternetAddress(mittente));
			message.addRecipient(Message.RecipientType.TO, new InternetAddress(destinatario));
			message.setSubject("MAIL_INVIATA_CON_JAVA");
			message.setText("questo messaggio è bello");
			Transport.send(message);
			System.out.println("MAIL INVIATA CORRETTAMENTE!");
		}catch(MessagingException mex) {
			mex.printStackTrace();
		}
	}
}
