## 5.3
- 3 Appui du bouton pause
Ici il s'agit d'une action du débogueur. Nous venons de faire une pause du programme et donc du microcontrolleur.
Le débogueur a donc arrêté l'horloge du processeur(action cpu correspondant à la pause). Le programme s'est arrêté dans le fichier  stm32f4xx_hal.c car c'est ce fichier qui s'occupe de l'abstraction du Hardware(Hardware Abstraction Layer-HAL).
Après plusieurs pauses du programme, nous remarquons que le programme s'arrete dans les fonctions suivantes : 
```
__weak uint32_t HAL_GetTick(void)
{
  return uwTick;
}
```
ou 
```
__weak void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;
  ...
  
  while((HAL_GetTick() - tickstart) < wait)
  {
  }
}
```
Ceci confirme bien que la pause arrête le tick d'horloge, arrêtant toute opération du processeur, étant donné que ce dernier n'effectue les opérations qu'après chaque tick d'horloge.

- 4. Add a variable to watch expression
Cliquez sur l’onglet main.c de la fenêtre File pour revenir à votre programme principal.
Double cliquez sur la variable Delay_time pour la surligner puis faite un clic droit puis Add
to watch expressions, cliquez sur OK, vous devriez obtenir la même fenêtre que la figure 20.
Que signifie Type et Value ?
Type est le type de la variable Delay_time et value la valeur de cette variable

- 5. HAL_Delay function purpose
 Double cliquez sur 250 et changer la valeur par 1000 ? Relancer ensuite le mode continu, que
s’est il passé ? A quoi sert donc la fonction HAL_Delay() ? (vous pouvez essayer plusieurs
valeur différentes).
HAL_Delay function aims to doing anything during a given milliseconds. It doesn't stop the processor, since it always executes the HAL_GetTick method. It just does anything for a given seconds.

- 6. Adding breakpoint in Resume mode
Placez un breakpoint à la ligne : ```if(GPIOD->ODR & 0x0000F000)``` (double clic dans la zone
bleue) Pourquoi la ligne devient elle verte ?
The program was in Resume mode, but after we've added a new breakpoint, the program has paused at the new added breakpoint. The reason is because we are in debug mode.
Now after clicking on Resume, the program stops at the same line. There was no breakpoint in the main.c file that is why before the resume mode does not stop at any execution step.

- 7. Screenshoting the memory
Cliquez sur l’onglet I/O Registers puis sur GPIO puis étendez GPIOD ; enfin double cliquez
sur GPIOD pour que celui ci et tous les registres dépendant deviennent verts. On remarque
que les champs ce remplissent. A quoi correspondent ils ?
Those values correspond to the GPIOD registers adress and there values

- 8. Updating the ODR (Output Data Register) from the debuger
Cherchez le registre ODR puis cliquez sur son champ Binary Value. Un mini menu apparait
avec des cases grises vous permettant de modifier chacun des bits du registre en cliquant
dessus. Inverser la valeur des bits : 15 14 13 12 puis appuyez sur Set (tout à droite du menu).
Visualisez l’effet sur la carte. Recommencez si besoin. Que s’est il passé ?
All the LEDs were off. After inversing the value of each bit 12,13,14 and 15, the corresponding LEDs were turned on