/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_practice;

import java.io.IOException;
import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

/**
 *
 * @author parve
 */
public class Lab_practice extends Application {
   
   
    @Override
    public void start(Stage primaryStage) throws IOException {
//        Button btn = new Button();
//        btn.setText("Click");
//
//        Button btn2 = new Button();
//        btn2.setText("Another Button");
//        btn2.setLayoutX(10);
//        btn2.setLayoutY(50);
//
//        btn.setOnAction(new EventHandler<ActionEvent>() {
//
//            @Override
//            public void handle(ActionEvent event) {
//                System.out.println("Hello World!");
//            }
//        });
//
//        btn2.setOnAction(e -> {
//            Alert alert = new Alert(Alert.AlertType.INFORMATION);
//            alert.setTitle("Title");
//            alert.setContentText("This is a alert message");
//            alert.show();
//        });
//
//        Pane root = new Pane();
////        root.getChildren().add(btn);
////        root.getChildren().add(btn2);
//            
//        root.getChildren().addAll(btn, btn2);

        FXMLLoader loader = new FXMLLoader(getClass().getResource("ui.fxml"));
        Parent root = loader.load();
        
        Scene scene = new Scene(root);

        primaryStage.setTitle("Lab4");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}
