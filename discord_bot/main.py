# Creare i restanti comandi di ricerca per gli altri argomenti del corso di analisi. 
import discord
from discord.ext import commands
import random
import webbrowser

TOKEN = 'ODA0MDIyODc3MDUyNjAwMzU1.YBGSpw.BQGpJLH6kEHWCCYJvP0neAnjEEY'

client = commands.Bot(command_prefix = '!')
client.remove_command('help')

@client.event 
async def on_ready(): 
    print('Il bot è in funzione!')
    
@client.command(aliases = ['cerca_i'])
async def cerca_integrali(ctx):
        link = ['https://www.youmath.it/esercizi/es-analisi-matematica/es-sugli-integrali/899-esercizi-integrali-definiti.html',
                'https://www.youmath.it/esercizi/es-analisi-matematica/es-sugli-integrali/900-esercizi-intermediate-integrali-definiti.html',
                'https://www.youmath.it/esercizi/es-analisi-matematica/es-sugli-integrali/901-esercizi-svolti-integrali-definiti.html',
                'https://www.youmath.it/esercizi/es-analisi-matematica/es-sugli-integrali/903-esercizi-svolti-intermedi-integrali-indefiniti.html',
                'https://www.youmath.it/esercizi/es-analisi-matematica/es-sugli-integrali/905-esercizi-risolti-integrali-indefiniti.html',
                'https://www.youmath.it/esercizi/es-analisi-matematica/es-sugli-integrali/904-esercizi-difficili-integrali-indefiniti.html',
                'http://calvino.polito.it/~terzafac/Corsi/analisi1/pdf/integrali-svolti.pdf',
                'http://www.sbai.uniroma1.it/~luisa.moschini/Inginformatica/INGinfdispensa1.pdf',
                'https://www.mat.uniroma2.it/~isola/teaching/AnalisiUno/5Integrali.pdf',
                'https://elearning.unipd.it/stat/pluginfile.php/35702/mod_resource/content/1/integrali.pdf',
                'https://www.studocu.com/it/document/universita-degli-studi-di-udine/analisi-matematica-1/altro/esercizi-svolti-con-soluzione-sugli-integrali-analisi-matematica-1/736466/view'
                ]
        # puoi cercare su internet www.webtutordimatematica.it
        stringa = random.choice(link)
        webbrowser.open(stringa)
        # await ctx.send(f'Ricerca per: {c}\nLink: {stringa}')
 
@client.command()
async def ping(ctx): 
    await ctx.send(f'Il ping del bot è: {round(client.latency * 1000)}ms')

# brief = 'questa funzione elimina il messaggio'
@client.command()
async def clear(ctx):
    amount = None
    await ctx.channel.purge(limit = amount)

@client.command(aliases = ['_todo'])
async def todo(ctx):
    risposte = ['Da fare: ripetere la teoria!',
                'Da fare: esercitarsi nel calcolo di limiti!',
                'Da fare: esercitarsi nel calcolo di integrali!',
                'Da fare: esercitarsi nello studio di funzione!', 
                'Da fare: esercitarsi nel determinare la convergenza di serie numeriche!',
                'Hai studiato abbastanza, puoi ripostarti!']
    await ctx.send (f'\n{random.choice(risposte)}\n')

@client.command(pass_context = True)
async def help(ctx): 
    author = ctx.message.author
    # channel = client.get_channel(804025410303426580)

    embed = discord.Embed(
        colour = discord.Colour.dark_red() 
    )
    embed.set_author(name = 'LISTA COMANDI DEL BOT')
    embed.add_field(name = '!help', value = 'Permette di visualizzare questa lista.', inline = False)
    embed.add_field(name = '!ping', value = 'Permette di visualizzare la latenza del bot.', inline = False)
    embed.add_field(name = '!clear', value = 'Pulisce la chat.', inline = False)
    embed.add_field(name = '!todo', value = 'Non sai cosa studiare? Ci pensa il bot!', inline = False)
    embed.add_field(name = '!cerca_i', value = 'Apre una pagina web per esercitarsi sugli integrali.', inline = False)
    embed.add_field(name = '!mot', value = 'Sei demoralizzato? Ci pensa il bot a consolarti, in un canale dedicato!', inline = False)
    embed.add_field(name = '!fight', value = 'Con testa o croce si risolvono tutti i problemi!', inline = False)

    await author.send(embed = embed)
    # await channel.send(embed = embed)
        
@client.command(pass_context = True)
async def fight(ctx):
    scelta = ['Vero', 'Falso']
    stringa = random.choice(scelta)
    await ctx.send(stringa)

@client.command(pass_context = True)
async def mot(ctx):
    channel = client.get_channel(804025410303426580) # Inserire l'ID del canale su cui si vuole la risposta del Bot.
    frasi = ['Inizia adesso. Non domani.',
            'Se non credi in te stesso, nessuno lo farà per te.',
            'Se è importante per te, troverai un modo.',
            'Soltanto chi osa spingersi un pò più in là scopre quanto può andare lontano.',
            'Anche quello esperto in tutto una volta era un principiante.',
            'Sembra sempre impossibile finchè non viene fatto.',
            'Ne varrà la pena.',
            'La vittoria è fatta di molte sconfitte.', 
            'Un desiderio non cambia niente, una decisione cambia tutto.',
            'Pensare è difficile, per questo la gente giudica.']
    stringa = random.choice(frasi)
    await channel.send(stringa)

client.run(TOKEN)