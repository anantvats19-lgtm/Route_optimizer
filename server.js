const express = require('express');
const { spawn } = require('child_process');
const path = require('path');

const app = express();
app.use(express.json());

app.get('/', (req, res) => res.sendFile(path.join(__dirname, 'index.html')));

app.post('/calculate', (req, res) => {
    console.log("Request received:", req.body);
    const { numPassengers, fuelPrice, mileage, wearTear, directDistances, matrix } = req.body;

    
    let inputData = `${numPassengers}\n${fuelPrice} ${mileage} ${wearTear}\n`;
    inputData += directDistances.join(' ') + '\n';
    matrix.forEach(row => { inputData += row.join(' ') + '\n'; });

    
    const cppProcess = spawn('./optimizer');
    let output = '';

    cppProcess.stdout.on('data', (data) => { output += data.toString(); });
    
    cppProcess.on('close', (code) => {
        if (code !== 0) return res.status(500).json({ error: "C++ Engine Failed" });
        try {
            res.json(JSON.parse(output));
        } catch (e) {
            res.status(500).json({ error: "Failed to parse C++ output" });
        }
    });

    
    cppProcess.stdin.write(inputData);
    cppProcess.stdin.end();
});

app.listen(3000, () => console.log('Carpool Server running at http://localhost:3000'));