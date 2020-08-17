const express = require('express');
const app = express();

app.get('/', (request, response) => {
    response.json({
        message: 'CIAO A TUTTI',
    });
});


app.listen(4242, () => {
    console.log("SERVER ATTIVO: http://localhost:4242");
});