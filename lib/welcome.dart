import 'package:flutter/material.dart';
import 'components/body.dart';

// ignore: use_key_in_widget_constructors
class Welcome extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return const Scaffold(
      body: Body(),
    );
  }
}
