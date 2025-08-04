# Mini R2D2 Inteligente con ESP32

⚠️ **Proyecto en desarrollo**

Este es un proyecto en curso para crear un pequeño robot inspirado en R2D2 que pueda pasear por la casa, evitando obstáculos con sensores infrarrojos. Además, estará conectado a Internet y a un servidor Ollama para interactuar y tener "vida" como un asistente divertido.

## Objetivo

Construir un robot móvil autónomo con ESP32 que:

- Detecte y evite obstáculos usando sensores IR.
- Se conecte a Internet WiFi para comunicación con servidores externos.
- Se integre con un servidor Ollama para chat inteligente y control.
- Actúe como asistente interactivo y entretenido en el hogar.

## Estado actual

El proyecto está en fases iniciales. Actualmente se cuenta con:

- Sensado de obstáculos con sensores IR.
- Código modularizado para sensores y control.
- Conectividad básica configurada.

Se planea integrar movimiento autónomo, comunicación avanzada y capacidades IA para dar "vida" al robot.

## Características

- Control de motores para movimiento básico.
- Sensores IR para evitar colisiones.
- Conexión WiFi para comunicación.
- Integración con servidor Ollama para respuestas y acciones inteligentes.
- Salidas visuales con LEDs y posible módulo de sonido.

## Componentes principales

- ESP32 Dev Kit
- Sensores infrarrojos de proximidad
- Driver y motores para movimiento
- LEDs indicadores
- Fuente de alimentación estable
- Servidor Ollama para inteligencia artificial

## Instalación y configuración

1. Clona este repositorio:

```bash
git clone 
cd 
```

2. Configura tu entorno ESP-IDF (ver documentación oficial).

3. Personaliza la configuración WiFi y servidor Ollama.

4. Compila y flashea el firmware:

```bash
idf.py build flash monitor
```

## Estructura del proyecto

- `components/sensor_ir/`: Código para el módulo sensor IR.
- `main/`: Código principal con lógica de navegación y comunicación.
- `CMakeLists.txt`: Configuración general del proyecto.

## Contribuciones

Este proyecto es open source y busca crecer con la comunidad. ¡Cualquier aporte es bienvenido!

## Licencia

MIT License
