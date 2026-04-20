# 🎆 Fireworks

This is the first project I made using C++ and SFML to create a fireworks simulation. The user can spawn fireworks at the bottom of the screen and see them fly up to the sky and explode. A fading effect is also added to make particles die over time.

## 💻 Technologies Used

* ```C++```

* ```SFML```

## 🃏 Features

1. Interactivity: the user can spawn a firework at the bottom of the screen, with a trail behind them and see them explode when reaching a certain height.
2. Fading Effect: each particle disappears over time by changing its color alpha value. When its lifetime is at maximum, its color is fullest.
3. Explosion And Trail Effect: when reaching a certain height, the particle explodes. The explosion and trail effect can be chosen by adjusting a parameter which can be: radial, ring, cone, directional, explosion with gravity and no gravity. 
   
## 🏫 What I Learned

Here is what I learned after completing the project:

1. Randomization: I learned to randomize particle parameters such as speed, angle and lifetime by using ```std::mt19937``` and ```std::random_device```.
2. Particle Update: I gave each particle specific parameters such as position, velocity, lifetime and angle. I used the first two to update the position, the lifetime to control when the particle died and the angle to control the direction by using trigonometric functions such as ```std::cos``` and ```std::sin```.
3. Multiple Emitters: I divided the code architecture into trail and explosion emitter. I kept track of when the firework's y position reached a certain height to swap from the first one to the second one.

## 💭 How Can It Be Improved?

- Different Firework Directions: currently the firework only goes straight up but what if I wanted one to go more to the left or right?
- More User Interface: by using buttons and texts. For example, adding a pause / restart button to inspect the simulation in real time or texts to show statistics / metrics.
- Sound: adding a sound each time a firework explodes adds a lot to the simulation, making it feel more alive with just that addition.

## 📝 Notes

You need to install ```SFML``` to run the project. I used [this version](https://www.sfml-dev.org/documentation/3.0.2/).

## 📹 Video
[Uploading fireworks.mp4…](https://github.com/user-attachments/assets/a4ac013b-99db-4f1c-bf80-a767f42ca4e7
)
