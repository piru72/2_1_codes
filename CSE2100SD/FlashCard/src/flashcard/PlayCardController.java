/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package flashcard;

import java.awt.Desktop;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.PrintWriter;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.ResourceBundle;
import java.util.Scanner;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javax.swing.JFileChooser;

/**
 * FXML Controller class
 *
 * @author parve
 */
public class PlayCardController implements Initializable {

    @FXML
    private AnchorPane scenePane;
    @FXML
    private Button exitButton;
    @FXML
    private Button createButton;
    @FXML
    private Button homeButton;

    @FXML
    private Button fileButton;

    @FXML
    private TextField textField;

    @FXML
    private Button nextButton;

    @FXML
    private Button showButton;

    Stage stage;
    String s1;

    int count = 1;
    int otherCount = 1;
    FileChooser obj1 = new FileChooser();

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }

    @FXML
    private void exitAction(ActionEvent event) {
        try {
            FileWriter fw = new FileWriter("card_1.txt");
            PrintWriter pw = new PrintWriter(fw);
            pw.write("");
            pw.flush();
            pw.close();
            stage = (Stage) exitButton.getScene().getWindow();
            stage.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @FXML
    private void createAction(ActionEvent event) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("createCard.fxml"));
            Parent root = loader.load();

            Scene scene = new Scene(root);

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            stage.setScene(scene);
            stage.setTitle("Create Flash Card");
            stage.show();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @FXML
    private void homeAction(ActionEvent event) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("FlashCard.fxml"));
            Parent root = loader.load();

            Scene scene = new Scene(root);

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            stage.setScene(scene);
            stage.setTitle("Flash Card");
            stage.show();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @FXML
    void fileAction(ActionEvent event) {

        System.out.println("File Action working");
        obj1.setTitle("Open File Dialog");
        obj1.getExtensionFilters().add(new FileChooser.ExtensionFilter("txt files", "*.txt"));
        File file = obj1.showOpenDialog(stage);
        try {
            if (file != null) {

                Desktop desktop = Desktop.getDesktop();

                s1 = file.getAbsolutePath();

                System.out.println(file.getAbsoluteFile());

                File file1 = new File(s1);
                if (file1.exists()) {
                    try {
                        FileReader fr = new FileReader(file1);
                        LineNumberReader lr = new LineNumberReader(fr);
                        while (lr.readLine() != null) {
                            totalLine++;
                        }
                        System.out.println("Total number of line of a txt file = " + totalLine);
                    } catch (FileNotFoundException ex) {
                        ex.printStackTrace();
                    } catch (IOException ex) {
                        ex.printStackTrace();
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }
    public int totalLine = 0;

    @FXML
    void nextAction(ActionEvent event) throws FileNotFoundException, IOException {

        System.out.println("Next Action working");

        File file = new File(s1);

        BufferedReader br = new BufferedReader(new FileReader(file));

        String st;

        int i = 0;
        while ((st = br.readLine()) != null) {
            if (questionNo == i) {
                textField.setText(st);
                if ((questionNo + 2) < totalLine) {
                    questionNo += 2;
                    break;
                }

                break;

            }
            i++;
        }
    }

    public int questionNo = 0;

    @FXML
    void showAction(ActionEvent event) throws IOException {
        System.out.println("Show Action working");

        File file = new File(s1);

        BufferedReader br = new BufferedReader(new FileReader(file));

        String st;
        if (questionNo%2 == 0)
        {
            questionNo -=1;
        }

        int i = 0;
        System.out.println("Value os question " + questionNo);
        while ((st = br.readLine()) != null) {
            if (questionNo == i) {
                textField.setText(st);
                questionNo++;

                break;

            }
            i++;
        }

    }

    @FXML
    void textAction(ActionEvent event) {
        System.out.println("Action working");
    }

}
