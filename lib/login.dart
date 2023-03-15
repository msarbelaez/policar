import 'package:flutter/material.dart';

class Login extends StatefulWidget {
  static String id = 'login';

  const Login({super.key});

  @override
  State<Login> createState() => _LoginState();
}

class _LoginState extends State<Login> {
  @override
  Widget build(BuildContext context) {
    // ignore: prefer_const_constructors
    return SafeArea(
      child: Scaffold(
        body: Center(
          child: Column(
            children: [
              Image.asset(
                'assets/images/logo.png',
                height: 500.0,
              ),
              const Text(
                "INICIO DE SESION",
                style: TextStyle(fontWeight: FontWeight.bold),
              ),
              const SizedBox(
                height: 15.0,
              ),
              _userTextField(),
              const SizedBox(
                height: 15,
              ),
              _passwordTextField(),
              const SizedBox(
                height: 20.0,
              ),
              _buttonLogin(),
              const Text(
                "Continua con",
                textAlign: TextAlign.center,
                overflow: TextOverflow.ellipsis,
                style: TextStyle(fontWeight: FontWeight.bold),
              ),
            ],
          ),
        ),
      ),
    );
  }

  Widget _userTextField() {
    return StreamBuilder(
      builder: (BuildContext context, AsyncSnapshot<dynamic> snapshot) {
        return Container(
          padding: const EdgeInsets.symmetric(horizontal: 20.0),
          child: TextField(
            keyboardType: TextInputType.emailAddress,
            decoration: const InputDecoration(
              icon: Icon(Icons.email),
              hintText: 'ejemplo@correo.com',
              labelText: 'Correo electronico',
            ),
            onChanged: (value) {},
          ),
        );
      },
    );
  }

  Widget _passwordTextField() {
    return StreamBuilder(
        builder: (BuildContext context, AsyncSnapshot<dynamic> snapshot) {
      return Container(
        padding: const EdgeInsets.symmetric(horizontal: 20.0),
        child: TextField(
          keyboardType: TextInputType.emailAddress,
          obscureText: true,
          decoration: const InputDecoration(
            icon: Icon(Icons.lock),
            hintText: 'Contraseña',
            labelText: 'Contraseña',
          ),
          onChanged: (value) {},
        ),
      );
    });
  }

  _buttonLogin() {
    return StreamBuilder(
        builder: (BuildContext context, AsyncSnapshot<dynamic> snapshot) {
      return ElevatedButton(
          onPressed: () {},
          child: Container(
            padding: const EdgeInsets.symmetric(horizontal: 80.0, vertical: 30),
          ));
    });
  }
}
