import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.KeyStroke;
import javax.swing.ScrollPaneConstants;
import javax.swing.JRadioButton;
import javax.swing.filechooser.FileNameExtensionFilter;


public class Dialogc extends JFrame{
	long object;
	int compiled;
	Image newImg;
	Image compileImg;
	Image openImg;
	Image runImg;
	Image saveImg;
	Image saveAsImg;
	String format;
	Boolean modified;
	String fieldsArray[];
	String buttonsArray[];
	JFileChooser fc;
	PrintWriter writer;
	File currentFile;
	Scanner helpScanner;
	Scanner scanner;
	JFrame helpWindow;
	JFrame dirWindow;
	JPanel dirChange;
	JTextArea helpText;
	JScrollPane helpScroll;
	JFrame aboutWindow;
	JLabel aboutLabel;
	JMenu file;
	JMenuItem save;
	JMenuItem open;
	JMenuItem New;
	JMenuItem saveAs;
	JMenuItem quit;
	JMenu compile;
	JMenuItem Compile;
	JMenuItem cRun;
	JMenu config;
	JMenuItem jCompile;
	JMenuItem cOptions;
	JMenuItem jRTime;
	JMenuItem rTimeOp;
	JMenuItem workDir;
	JMenuItem compileMode;
	JMenu help;
	JMenuItem Help;
	JMenuItem about;
	JMenuBar bar;
	JPanel statusBar;
	JPanel buttonPanel;
	JButton newButton;
	JButton openButton;
	JButton saveButton;
	JButton saveAsButton;
	JButton compileButton;
	JButton runButton;
	JTextArea text;
	JScrollPane scroll;
	JLabel status;
	JTextField directoryField;
	JLabel dirLabel;
	JButton change;
	JButton dismiss;
	JFrame lexFrame;
	JPanel lexPanel; 
	JRadioButton lex;
	JRadioButton dialogc;
	
	String directory = System.getProperty("user.dir");
	native int PM_parse(long ParameterManger, String fp, char comment);
	static{
		System.loadLibrary("JNIpm");
	}
	native long PM_create(int size);
	static{
		System.loadLibrary("JNIpm");
	}
	native int PM_destroy(long p);
	static{
		System.loadLibrary("JNIpm");
	}
	native int PM_manage(long p, String pname, int type , int required);
	static{
		System.loadLibrary("JNIpm");
	}
	native String[] PM_getList(long p, String pname);
	static{
		System.loadLibrary("JNIpm");
	}
	native String PM_getString(long p, String pname);
	static{
		System.loadLibrary("JNIpm");
	}
	
	
	public Dialogc(){
		super("Dialogc");
		setSize(1000,600);
		setResizable(false);
		setLayout(new BorderLayout());
		setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		addWindowListener(new WindowAdapter(){
			@Override
			public void windowClosing (WindowEvent e){
				if(!text.getText().equals("") && currentFile==null){
					if(JOptionPane.showConfirmDialog(null, "You have a modified file open...\nWould you like to save before quitting?")==0){
						save();
						System.exit(0);
					}
				}
				if(modified == true){
					if(JOptionPane.showConfirmDialog(null, "You have a modified file open...\nWould you like to save before quitting?")==0){
						save();
						System.exit(0);
					}
					else{
						System.exit(0);
					}
				}
				else if(JOptionPane.showConfirmDialog(null, "Are you sure you would like to quit?")==0){
					System.exit(0);
				}
			}
		});
		/*Create menu bar for file, config, help, compile*/
		/*File drop down bar*/
		file = new JMenu("File");
		New = new JMenuItem("New");
		New.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_N, java.awt.Event.CTRL_MASK));
		New.addActionListener(new menuListener());
		open = new JMenuItem("Open");
		open.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_O, java.awt.Event.CTRL_MASK));
		open.addActionListener(new menuListener());
		save = new JMenuItem("Save");
		save.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_S, java.awt.Event.CTRL_MASK));
		save.addActionListener(new menuListener());
		saveAs = new JMenuItem("Save As");
		saveAs.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_S, java.awt.Event.ALT_MASK));
		saveAs.addActionListener(new menuListener());
		quit = new JMenuItem("Quit");
		quit.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_Q, java.awt.Event.CTRL_MASK));
		quit.addActionListener(new menuListener());
		
		file.add(New);
		file.add(open);
		file.add(save);
		file.add(saveAs);
		file.add(quit);
		
		/*Compile drop down bar*/
		compile = new JMenu("Compile");
		Compile = new JMenuItem("Compile");
		Compile.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_B, java.awt.Event.CTRL_MASK));
		Compile.addActionListener(new menuListener());
		cRun = new JMenuItem("Compile & Run");
		cRun.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_R, java.awt.Event.CTRL_MASK));
		cRun.addActionListener(new menuListener());
		
		compile.add(Compile);
		compile.add(cRun);
		
		/*config bar*/
		config = new JMenu("Config");
	    jCompile = new JMenuItem("Java Compiler");
	    jCompile.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_B, java.awt.Event.ALT_MASK));
	    jCompile.addActionListener(new menuListener());
		cOptions = new JMenuItem("Compile Options");
		cOptions.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_C, java.awt.Event.ALT_MASK));
		cOptions.addActionListener(new menuListener());
		jRTime = new JMenuItem("Java Run-time");
		jRTime.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_J, java.awt.Event.CTRL_MASK));
		jRTime.addActionListener(new menuListener());
		rTimeOp = new JMenuItem("Run-Time Options");
		rTimeOp.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_R, java.awt.Event.ALT_MASK));
		rTimeOp.addActionListener(new menuListener());
		workDir = new JMenuItem("Working Directory");
		workDir.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_D, java.awt.Event.CTRL_MASK));
		workDir.addActionListener(new menuListener());
		compileMode = new JMenuItem("Compile Mode");
		compileMode.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_M, java.awt.Event.CTRL_MASK));
		compileMode.addActionListener(new menuListener());
		
		config.add(jCompile);
		config.add(cOptions);
		config.add(jRTime);
		config.add(rTimeOp);
		config.add(workDir);
		config.add(compileMode);
		
		/*Help drop down bar*/
		help = new JMenu("Help");
		Help = new JMenuItem("Help");
		Help.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_H, java.awt.Event.CTRL_MASK));
		Help.addActionListener(new menuListener());
		about = new JMenuItem("About");
		about.setAccelerator(KeyStroke.getKeyStroke(java.awt.event.KeyEvent.VK_A, java.awt.Event.CTRL_MASK));
		about.addActionListener(new menuListener());
		help.add(Help);
		help.add(about);
		
		bar = new JMenuBar();
		bar.add(file);
		bar.add(compile);
		bar.add(config);
		bar.add(help);
		setJMenuBar(bar);
		
		/*Create Buttons*/
		buttonPanel = new JPanel();
		buttonPanel.setLayout(new GridLayout(0,6));
		newButton = new JButton("New");
		try{
			newImg = ImageIO.read(getClass().getResource("/images/new.png"));
			newButton.setIcon(new ImageIcon(newImg));
    	} catch(IOException ex){
			JOptionPane.showMessageDialog(null, "Could not load new button image");
		}
		newButton.addActionListener(new buttonListener());
		openButton = new JButton("Open");
		try{
			openImg = ImageIO.read(getClass().getResource("/images/folder_open.png"));
			openButton.setIcon(new ImageIcon(openImg));
    	} catch(IOException ex){
			JOptionPane.showMessageDialog(null, "Could not load open button image");
		}
		openButton.addActionListener(new buttonListener());
		saveButton = new JButton("Save");
		try{
			saveImg = ImageIO.read(getClass().getResource("/images/save.png"));
			saveButton.setIcon(new ImageIcon(saveImg));
    	} catch(IOException ex){
			JOptionPane.showMessageDialog(null, "Could not load save button image");
		}
		saveButton.addActionListener(new buttonListener());
		saveAsButton = new JButton("Save As");
		try{
			saveAsImg = ImageIO.read(getClass().getResource("/images/save_as.png"));
			saveAsButton.setIcon(new ImageIcon(saveAsImg));
    	} catch(IOException ex){
			JOptionPane.showMessageDialog(null, "Could not load save_as button image");
		}
		saveAsButton.addActionListener(new buttonListener());
		compileButton = new JButton("Compile");
		try{
			compileImg = ImageIO.read(getClass().getResource("/images/compile.png"));
			compileButton.setIcon(new ImageIcon(compileImg));
    	} catch(IOException ex){
			JOptionPane.showMessageDialog(null, "Could not load save_as button image");
		}
		compileButton.addActionListener(new buttonListener());
		runButton = new JButton("Run");
		try{
			runImg = ImageIO.read(getClass().getResource("/images/run.png"));
			runButton.setIcon(new ImageIcon(runImg));
    	} catch(IOException ex){
			JOptionPane.showMessageDialog(null, "Could not load save_as button image");
		}
		runButton.addActionListener(new buttonListener());
		buttonPanel.add(newButton);
		buttonPanel.add(openButton);
		buttonPanel.add(saveButton);
		buttonPanel.add(saveAsButton);
		buttonPanel.add(compileButton);
		buttonPanel.add(runButton);
		buttonPanel.setVisible(true);
		add(buttonPanel, BorderLayout.NORTH);
		/*Add text area with scroll bar*/
		text = new JTextArea();
		text.addKeyListener(new textListener());
		scroll = new JScrollPane(text);
		scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		scroll.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS);
		add(scroll, BorderLayout.CENTER);
		
		statusBar = new JPanel();
		status = new JLabel();
		status.setText("Current Project: ");
		statusBar.add(status);
		add(statusBar, BorderLayout.SOUTH);
		statusBar.setVisible(true);
		
		/*Initialize new help window*/
		helpWindow = new JFrame("Help");
		helpWindow.setSize(600,600);
		helpWindow.setLayout(new BorderLayout());
		helpText = new JTextArea();
		helpText.enableInputMethods(false);
		helpScroll = new JScrollPane(helpText);
		helpScroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		helpScroll.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS);
		helpWindow.add(helpScroll, BorderLayout.CENTER);
		helpWindow.setVisible(false);
		try{
			helpScanner = new Scanner(new File("README.txt"));
			while(helpScanner.hasNext()){
				helpText.setText(helpText.getText()+helpScanner.nextLine()+"\n");
			}
		}catch(FileNotFoundException e1){
			JOptionPane.showMessageDialog(null, "File: \"README.txt\" not found.");
		}
		/*About window Intialization*/
		aboutWindow = new JFrame("About");
		aboutWindow.setSize(200,200);
		aboutWindow.setLayout(new BorderLayout());
		aboutLabel = new JLabel();
		aboutLabel.setText("<html>Name: Lucas Boyd<br>Stundent Number: 0795339<br>Course: CIS*2750<br>Assignment Number: 2<br><html>");
		aboutWindow.add(aboutLabel, BorderLayout.CENTER);
		aboutWindow.setVisible(false);
		
		/*Directory window initializer*/
		dirWindow = new JFrame("Dialogc");
		dirWindow.setLayout(new BorderLayout());
		dirWindow.setSize(400,100);
		dirWindow.setVisible(false);
		dirWindow.setResizable(true);
		dirChange = new JPanel();
		dirChange.setLayout(new FlowLayout());
		dirLabel = new JLabel("Curent Directory: ");
		directoryField = new JTextField(directory);
		directoryField.setSize(200, 10);
		change = new JButton("Change");
		change.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e) {
				File newDirectory = new File(directoryField.getText());
					if(newDirectory.exists()){
						directory = directoryField.getText();
						JOptionPane.showMessageDialog(null, "Directory changed.");
					}
					else{
						if(JOptionPane.showConfirmDialog(null, "Directory Does not exist. Would you like to create a new folder?\n")==0){
							newDirectory.mkdir();
							directory = directoryField.getText();
						}
						else{
							JOptionPane.showMessageDialog(null,"No changes.\n");
						}
					}
				}
		});
		dismiss = new JButton("Dismiss");
		dismiss.addActionListener(new ActionListener(){
			public void actionPerformed (ActionEvent e){
				dirWindow.setVisible(false);			
			}
		});
		dirChange.add(dirLabel);
		dirChange.add(directoryField);
		dirChange.add(change);
		dirChange.add(dismiss);
		dirWindow.add(dirChange, BorderLayout.CENTER);
		
		modified = false;
		fc = new JFileChooser();
		FileNameExtensionFilter filter = new FileNameExtensionFilter("CONFIG FILES", "config", "text");
		fc.setFileFilter(filter);
		setVisible(true);

		lexFrame = new JFrame("Dialogc");
		lexFrame.setLayout(new BorderLayout());
		lexFrame.setSize(400,100);
		lexFrame.setVisible(false);
		lexFrame.setResizable(true);
		lexPanel = new JPanel();
		lexPanel.setLayout(new FlowLayout());
		lex = new JRadioButton("lex/yacc");
		dialogc = new JRadioButton("Default");
		lex.addActionListener(new ActionListener(){
			public void actionPerformed (ActionEvent e){
				lex.setSelected(true);
				dialogc.setSelected(false);
			}
		});
		dialogc.addActionListener(new ActionListener(){
			public void actionPerformed (ActionEvent e){
				lex.setSelected(false);
				dialogc.setSelected(true);
			}
		});
		dialogc.setSelected(true);
		lexPanel.add(dialogc);
		lexPanel.add(lex);
		lexFrame.add(lexPanel, BorderLayout.CENTER);
	}
	public class textListener implements KeyListener{

		@Override
		public void keyPressed(KeyEvent arg0) {
			if(currentFile!=null){
				status.setText("Current Project: "+currentFile.getName()+" [Modified]");
				modified = true;
				compiled = 0;
			}
		}

		@Override
		public void keyReleased(KeyEvent arg0) {
			if(currentFile!=null){
				status.setText("Current Project: "+currentFile.getName()+" [Modified]");
				modified = true;
				compiled = 0;
			}
		}

		@Override
		public void keyTyped(KeyEvent arg0) {
			if(currentFile!=null){
				status.setText("Current Project: "+currentFile.getName()+" [Modified]");
				modified = true;
				compiled = 0;
			}
		}
			
	}
	public class menuListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e){
			String choice = e.getActionCommand();
			if(choice.equals("New")){
			    New();
			}
			else if(choice.equals("Open")){
			    open();
			}
			else if(choice.equals("Save")){
                            save();
			}
			else if(choice.equals("Save As")){
                            saveAs();
			}
			else if(choice.equals("Compile")){
                            compile();
			}
			else if(choice.equals("Quit")){
                            if(!text.getText().equals("") && currentFile==null){
					if(JOptionPane.showConfirmDialog(null, "You have a modified file open...\nWould you like to save before quitting?")==0){
						save();
						System.exit(0);
					}
				}
				if(modified == true){
					if(JOptionPane.showConfirmDialog(null, "You have a modified file open...\nWould you like to save before quitting?")==0){
						save();
						System.exit(0);
					}
					else{
						System.exit(0);
					}
				}
				else if(JOptionPane.showConfirmDialog(null, "Are you sure you would like to quit?")==0){
					System.exit(0);
				}
			}
			else if(choice.equals("Compile & Run")){
                            compile();
                            if(compiled == 1){
                               run();
                            }
			}
			else if(choice.equals("Compiler Options")){
			    JOptionPane.showMessageDialog(null, "not implemented\n");
			}
			else if(choice.equals("Java Compiler")){
			    JOptionPane.showMessageDialog(null, "not implemented\n");
			}
			else if(choice.equals("Compile Options")){
			    JOptionPane.showMessageDialog(null, "not implemented\n");
			}
			else if(choice.equals("Java Run-Time")){
			    JOptionPane.showMessageDialog(null, "not implemented\n");
			}
			else if(choice.equals("Run-time Options")){
			    JOptionPane.showMessageDialog(null, "not implemented\n");
			}
			else if(choice.equals("Working Directory")){
			    directoryField.setText(directory);
			    dirWindow.setVisible(true);
			}
			else if(choice.equals("Compile Mode")){
				lexFrame.setVisible(true);
			}
			else if(choice.equals("Help")){
			    helpWindow.setVisible(true);
			}
			else if(choice.equals("About")){
			    aboutWindow.setVisible(true);
			}	
		}
	}
	public void save(){
		int returnVal = 0;
		if(currentFile!=null){
			try {
				writer = new PrintWriter(currentFile);
				text.write(writer);
				status.setText("Current Project: "+currentFile.getName()+" [saved]");
			} catch (FileNotFoundException e1) {
				JOptionPane.showMessageDialog(null, "File not Found");
			} catch (IOException e1) {
				JOptionPane.showMessageDialog(null, "Unable to write to file.");
			}
		}
		else{
			returnVal = fc.showSaveDialog(null);
			if(returnVal == JFileChooser.APPROVE_OPTION){
				currentFile = fc.getSelectedFile();
				try {
					writer = new PrintWriter(currentFile);
					text.write(writer);
					status.setText("Current Project: "+currentFile.getName()+" [saved]");
				} catch (FileNotFoundException e1) {
					JOptionPane.showMessageDialog(null, "File not Found");
				} catch (IOException e1) {
					JOptionPane.showMessageDialog(null, "Unable to write to file.");
				}
			}
		}
		modified = false;
	}
	public void open(){
		int returnVal=0;
		returnVal = fc.showOpenDialog(null);				
		if(returnVal == JFileChooser.APPROVE_OPTION){
			currentFile = fc.getSelectedFile();
			try {
				scanner = new Scanner(currentFile);
				status.setText("Current Project: "+currentFile.getName());
				text.setText("");
				while(scanner.hasNext()){
					text.setText(text.getText()+scanner.nextLine()+"\n");
				}
			} catch (FileNotFoundException e1) {
				JOptionPane.showMessageDialog(null, "File not Found");
			}
			while(scanner.hasNext()){
				text.setText(text.getText()+scanner.nextLine()+"\n");
			}
		}
	}
	public void saveAs(){
		int returnVal = 0;
		returnVal = fc.showSaveDialog(null);
		if(returnVal == JFileChooser.APPROVE_OPTION){
			currentFile = fc.getSelectedFile();
			try {
				writer = new PrintWriter(currentFile);
				text.write(writer);
				status.setText("Current Project: "+currentFile.getName()+" [saved]");
			} catch (FileNotFoundException e1) {
				JOptionPane.showMessageDialog(null, "File not Found");
			} catch (IOException e1) {
				JOptionPane.showMessageDialog(null, "Unable to write to file.");
			}
		}
		modified = false;
	}
	
	public void compile(){
		if(modified == true){
			save();
			modified = false;
		}
		if(!text.getText().equals("")){
			save();
		}
		if(currentFile!=null){
			if(dialogc.isSelected()){
				int i=0;
				object = PM_create(12);
				PM_manage(object, "title", 3, 1);
				PM_manage(object, "fields", 4, 1);
				PM_manage(object, "buttons", 4, 1);
				try{
					if(PM_parse(object, currentFile.getName(), '#')!=0){
						fieldsArray =  PM_getList(object, "fields");
						buttonsArray = PM_getList(object, "buttons");
						try {
							writer = new PrintWriter(directory +"/"+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+".java", "UTF-8");
							writer.println("import java.awt.*;");
							writer.println("import javax.swing.*;");
							writer.println("import java.awt.event.ActionListener;");
							writer.println("import java.awt.event.ActionEvent;");
							writer.println("public class "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+" implements "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+"FieldEdit"+"{");
							writer.println("    JFrame main;");
							writer.println("    JPanel top = new JPanel();");
							writer.println("    JPanel bot = new JPanel();");
							writer.println("    JPanel field = new JPanel();");
							writer.println("    JPanel buttonArea= new JPanel();");
							for(i=0; i<fieldsArray.length; i++){
								writer.println("    JTextField "+fieldsArray[i]+"Text;");
							}
							writer.println("    JTextArea textArea;");
							writer.println("    JButton button;");
							writer.println("    JLabel statusLabel;");
							writer.println("    int i;");
							writer.println("    public "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+"(){");
							format = String.format("        main = new JFrame(\"%s\");", PM_getString(object, "title"));
							writer.println(format);
							writer.println("        main.setSize(400,400);");
							writer.println("        main.setResizable(false);");
							writer.println("        main.setLayout(new BorderLayout());");
							writer.println("        main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);");
							writer.println("        top.setLayout(new BoxLayout(top, BoxLayout.Y_AXIS));");
							writer.println("        bot.setLayout(new BoxLayout(bot, BoxLayout.Y_AXIS));");
							writer.println("        buttonArea.setLayout(new FlowLayout());");
							format = String.format("        field.setLayout(new GridLayout(%d, 2, 1, 2));", fieldsArray.length);
							writer.println(format);
							for(i=0; i<fieldsArray.length; i++){
								format = String.format("        JLabel "+fieldsArray[i]+"Label = new JLabel(\"%s\");", fieldsArray[i]);
								writer.println(format);
								writer.println("        "+fieldsArray[i]+"Text = new JTextField();");
								writer.println("        field.add("+fieldsArray[i]+"Label"+");");
								writer.println("        field.add("+fieldsArray[i]+"Text"+");");
							}
							writer.println("        top.add(field);");
							for(i=0; i<buttonsArray.length; i++){
								format = String.format("        button = new JButton(\"%s\");", buttonsArray[i]);
								writer.println(format);
								writer.println("        button.addActionListener(new ActionListener(){");
								writer.println("            @Override");
								writer.println("            public void actionPerformed(ActionEvent e){");
								writer.println("                textArea.append(e.getActionCommand() + \"button pushed.\");");
								writer.println("            }");
								writer.println("        });");
								writer.println("        buttonArea.add(button);");
							}
							writer.println("        top.add(buttonArea);");
							writer.println("        statusLabel = new JLabel(\"status\");");
							writer.println("        bot.add(statusLabel);");
							writer.println("        textArea = new JTextArea();");
							writer.println("        JScrollPane scroll = new JScrollPane(textArea);");
							writer.println("        scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);");
							writer.println("        bot.add(scroll);");
							writer.println("        main.add(top, BorderLayout.NORTH);");
							writer.println("        main.add(bot, BorderLayout.CENTER);");
							writer.println("        main.setVisible(true);");
							writer.println("    }");
							for(i=0; i<fieldsArray.length; i++){
								writer.println("    public String getDC"+fieldsArray[i]+"(){");
								writer.println("        return("+fieldsArray[i]+"Text.getText());");
								writer.println("    }");
								writer.println("    public void setDC"+fieldsArray[i]+"(String input){");
								writer.println("        "+fieldsArray[i]+"Text.setText(input);");
								writer.println("    }");
							}
							writer.println("    public void appanedToStatusArea(String message){");
							writer.println("        textArea.append(message);");
							writer.println("    }");
							writer.println("    public static void main(String[] args){");
							writer.println("        "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+" window = new "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+"();");
							writer.println("    }");
							writer.println("}");
							writer.close();
							writer = new PrintWriter(directory+"/"+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+"FieldEdit.java","UTF-8");
							writer.println("import java.awt.*;");
							writer.println("import javax.swing.*;");
							writer.println("import java.awt.event.ActionListener;");
							writer.println("import java.awt.event.ActionEvent;");
							writer.println("public interface "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+"FieldEdit"+"{");
							for(i=0; i<fieldsArray.length; i++){
								writer.println("    public String getDC"+fieldsArray[i]+"();");
								writer.println("    public void setDC"+fieldsArray[i]+"(String input);");
							}
							writer.println("    public void appanedToStatusArea(String message);");
							writer.println("}");
							writer.close();
						} catch (FileNotFoundException e) {
							System.out.print("Error File no found\n");
						} catch (UnsupportedEncodingException e) {
							
						}
						try {
							Process proOne = Runtime.getRuntime().exec("javac -d "+directory+" "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+".java");
							if(proOne.waitFor()==0){
								Process proTwo = Runtime.getRuntime().exec("javac -d "+directory+" "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+"FieldEdit.java");
								if(proTwo.waitFor()==0){
									compiled = 1;
								}
							}
						} catch (IOException e) {
							
						}
						status.setText("Current Project: "+currentFile.getName()+" [compiled]");
					}
				}catch(Exception e){
					JOptionPane.showMessageDialog(null, "Compile error\n");
				}
			}
			else{
				try {
					Process yac = Runtime.getRuntime().exec("./yadc "+currentFile.getName()+" "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+" "+directory);
					Process proOne = Runtime.getRuntime().exec("javac -d "+directory+" "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+".java");
					System.out.println("javac -d "+directory+" "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+".java");
					if(proOne.waitFor()==0){
						Process proTwo = Runtime.getRuntime().exec("javac -d "+directory+" "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.'))+"FieldEdit.java");
						if(proTwo.waitFor()==0){
								compiled = 1;
						}
					}
				} catch (IOException e) {
					
				} catch (InterruptedException e) {
					
				}
				status.setText("Current Project: "+currentFile.getName()+" [compiled]");
			}
		}
		else{
			status.setText("Error: no file found.");
		}
	}
	
	public void run(){
		try{
			Runtime.getRuntime().exec("java"+" -cp "+directory+" "+currentFile.getName().substring(0, currentFile.getName().lastIndexOf('.')));
		}catch(Exception e){
			System.out.printf("Something happend\n");
		}
	}
	public void New(){
		if(currentFile!=null && modified){
			if(JOptionPane.showConfirmDialog(null, "You have an unsaved file would you like to save before opening?") == 0){
				save();
				currentFile = new File(JOptionPane.showInputDialog(null, "name of the new File?")+".config");
				modified = false;
				compiled = 0;
				text.setText("");
				status.setText("");
			}
		}
		else{
			currentFile = new File(JOptionPane.showInputDialog(null, "name of the new File?")+".config");
			modified=false;
			text.setText("");
		}
	}
	public class buttonListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e){
			String choice = e.getActionCommand();
			if(choice.equals("New")){
			    New();
			}
			else if(choice.equals("Open")){
			    open();
			}
			else if(choice.equals("Save")){
                            save();
			}
			else if(choice.equals("Save As")){
                            saveAs();
			}
			else if(choice.equals("Compile")){
                            compile();
			}
			else if(choice.equals("Run")){
                            compile();
                            if(compiled == 1){
                               run();
                            }
			}
		}
	}
	
	
	public static void main(String[] args){
		Dialogc test;
		test = new Dialogc();
	}
}
