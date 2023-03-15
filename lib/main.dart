import 'package:flutter/material.dart';
import 'constants.dart';
import 'login.dart';
import 'welcome.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Car Demo',
      theme: ThemeData(
        primaryColor: kPrimaryColor,
        scaffoldBackgroundColor: Colors.white,
      ),
      home: Welcome(),
      initialRoute: Login.id,
      routes: {
        Login.id: (context) => const Login(),
      },
    );
  }
  /* initialRoute: Login.id,
      routes: {
        Login.id: (context) => const Login();
      }*/
}
